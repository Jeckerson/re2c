#include <stddef.h>
#include "src/util/c99_stdint.h"
#include <string>
#include <utility>
#include <vector>

#include "src/adfa/adfa.h"
#include "src/codegen/bitmap.h"
#include "src/codegen/emit.h"
#include "src/codegen/go.h"
#include "src/codegen/label.h"
#include "src/codegen/output.h"
#include "src/codegen/print.h"
#include "src/options/opt.h"
#include "src/dfa/tcmd.h"
#include "src/encoding/enc.h"


namespace re2c {

static std::string gen_if(const opt_t *opts, const std::string &compare, uint32_t value)
{
    std::ostringstream os;
    const Enc &e = opts->encoding;
    os << opts->yych << " " << compare << " ";
    prtChOrHex(os, value, e.szCodeUnit(), e.type() == Enc::EBCDIC,
        opts->target == TARGET_DOT);
    return os.str();
}

CodeStmts *Cases::emit(Output &output, const DFA &dfa, const State *from) const
{
    const opt_t *opts = output.block().opts;
    code_alc_t &alc = output.allocator;
    Scratchbuf &o = output.scratchbuf;

    CodeText expr = o.str(opts->yych).flush();
    CodeCases *ccases = code_cases(alc);
    for (uint32_t i = 0; i < cases_size; ++i) {
        const Case &c = cases[i];
        CodeStmts *body = code_stmts(alc);
        gen_goto(output, body, from, c.to, dfa, c.tags, c.skip, c.eof);
        append(ccases, code_case_chars(alc, body, c.ranges));
    }
    CodeStmts *stmts = code_stmts(alc);
    append(stmts, code_switch(alc, expr, ccases, true));

    return stmts;
}

CodeStmts *Binary::emit(Output &output, const DFA &dfa, const State *from) const
{
    const opt_t *opts = output.block().opts;
    code_alc_t &alc = output.allocator;
    Scratchbuf &o = output.scratchbuf;

    CodeStmts *stmts = code_stmts(alc);
    CodeText if_cond = o.str(gen_if(opts, cond->compare, cond->value)).flush();
    CodeStmts *if_then = thn->emit(output, dfa, from);
    CodeStmts *if_else = els->emit(output, dfa, from);
    append(stmts, code_stmt_if_then_else(alc, if_cond, if_then, if_else));

    return stmts;
}

CodeStmts *Linear::emit(Output &output, const DFA &dfa, const State *from) const
{
    const opt_t *opts = output.block().opts;
    code_alc_t &alc = output.allocator;
    Scratchbuf &o = output.scratchbuf;

    CodeStmts *stmts = code_stmts(alc);
    for (uint32_t i = 0; i < nbranches; ++i) {
        const Branch &b = branches[i];
        const Cond *cond = b.cond;
        if (cond) {
            CodeText if_cond = o.str(gen_if(opts, cond->compare, cond->value)).flush();
            CodeStmts *if_then = code_stmts(alc);
            gen_goto(output, if_then, from, b.to, dfa, b.tags, b.skip, b.eof);
            append(stmts, code_stmt_if_then_else(alc, if_cond, if_then, NULL));
        }
        else {
            gen_goto(output, stmts, from, b.to, dfa, b.tags, b.skip, b.eof);
        }
    }
    return stmts;
}

CodeStmts *If::emit(Output &output, const DFA &dfa, const State *from) const
{
    return type == BINARY
        ? info.binary->emit(output, dfa, from)
        : info.linear->emit(output, dfa, from);
}

CodeStmts *SwitchIf::emit(Output &output, const DFA &dfa, const State *from) const
{
    return type == SWITCH
        ? info.cases->emit(output, dfa, from)
        : info.ifs->emit(output, dfa, from);
}

CodeStmts *GoBitmap::emit(Output &output, const DFA &dfa, const State *from) const
{
    const opt_t *opts = output.block().opts;
    code_alc_t &alc = output.allocator;
    Scratchbuf &o = output.scratchbuf;

    CodeStmts *stmts = code_stmts(alc);

    o.str(opts->yybm).cstr("[").u32(bitmap->i).cstr("+").str(opts->yych).cstr("] & ");
    if (opts->yybmHexTable) {
        o.u32_hex(bitmap->m, opts);
    }
    else {
        o.u32(bitmap->m);
    }
    CodeText elif_cond = o.flush();

    CodeStmts *if_else = code_stmts(alc);
    gen_goto(output, if_else, from, bitmap_state, dfa, TCID0, false, false);

    if (hgo != NULL) {
        CodeText if_cond = o.str(opts->yych).cstr(" & ~0xFF").flush();
        CodeStmts *if_then = hgo->emit(output, dfa, from);
        append(stmts, code_stmt_if_then_elif(alc, if_cond, if_then, elif_cond,
            if_else));
    }
    else {
        append(stmts, code_stmt_if_then_else(alc, elif_cond, if_else, NULL, false));
    }

    if (lgo != NULL) {
        append(stmts, lgo->emit(output, dfa, from));
    }

    return stmts;
}

label_t CpgotoTable::max_label () const
{
    label_t max = label_t::first();
    for (uint32_t i = 0; i < TABLE_SIZE; ++i) {
        if (max < table[i]->label) {
            max = table[i]->label;
        }
    }
    return max;
}

CodeStmts *CpgotoTable::emit(Output &output) const
{
    const uint32_t max_digits = max_label ().width ();
    static const size_t TABLE_WIDTH = 8;
    const opt_t *opts = output.block().opts;
    code_alc_t &alc = output.allocator;
    Scratchbuf &o = output.scratchbuf;
    CodeText text;

    CodeStmts *stmts = code_stmts(alc);

    text = o.cstr("static void *").str(opts->yytarget).cstr("[256] = {").flush();
    append(stmts, code_stmt_text(alc, text));

    CodeStmts *block = code_stmts(alc);
    for (uint32_t i = 0; i < TABLE_SIZE / TABLE_WIDTH; ++i) {
        for (uint32_t j = 0; j < TABLE_WIDTH; ++j) {
            const label_t &l = table[i * TABLE_WIDTH + j]->label;
            o.cstr("&&").str(opts->labelPrefix).label(l);

            if (j < TABLE_WIDTH - 1) {
                const std::string padding(max_digits - l.width() + 1, ' ');
                o.cstr(",").str(padding);
            }
            else if (i < TABLE_SIZE / TABLE_WIDTH - 1) {
                o.cstr(",");
            }
        }
        text = o.flush();
        append(block, code_stmt_text(alc, text));
    }
    append(stmts, code_block(alc, block, CodeBlock::INDENTED));

    append(stmts, code_stmt_text(alc, "};"));

    return stmts;
}

CodeStmts *Cpgoto::emit(Output &output, const DFA &dfa, const State *from) const
{
    const opt_t *opts = output.block().opts;
    code_alc_t &alc = output.allocator;
    Scratchbuf &o = output.scratchbuf;
    CodeText text;

    CodeStmts *stmts = code_stmts(alc);

    CodeStmts *if_else = table->emit(output);
    text = o.cstr("goto *").str(opts->yytarget).cstr("[").str(opts->yych).cstr("];")
        .flush();
    append(if_else, code_stmt_text(alc, text));

    if (hgo != NULL) {
        CodeText if_cond = o.str(opts->yych).cstr(" & ~0xFF").flush();
        CodeStmts *if_then = hgo->emit(output, dfa, from);
        append(stmts, code_stmt_if_then_else(alc, if_cond, if_then, if_else,
            false));
    }
    else {
        append(stmts, code_block(alc, if_else, CodeBlock::WRAPPED));
    }

    return stmts;
}

void Dot::emit(Output &output, const DFA &dfa, const State *from, CodeStmts *stmts) const
{
    const opt_t *opts = output.block().opts;
    code_alc_t &alc = output.allocator;
    Scratchbuf &o = output.scratchbuf;
    const std::string &prefix = opts->tags_prefix;
    const uint32_t n = cases->cases_size;
    CodeText text;

    if (n == 1) {
        text = o.label(from->label).cstr(" -> ").label(cases->cases[0].to->label)
            .flush();
        append(stmts, code_stmt_text(alc, text));
    }
    else {
        for (uint32_t i = 0; i < n; ++i) {
            const Case &c = cases->cases[i];
            o.label(from->label).cstr(" -> ").label(c.to->label).cstr(" [label=\"");
            for (uint32_t j = 0; j < c.ranges.size(); ++j) {
                const Enc &e = opts->encoding;
                printSpan(o.stream(), c.ranges[j].first, c.ranges[j].second,
                    e.szCodeUnit(), e.type() == Enc::EBCDIC, true);
            }
            const tcmd_t *cmd = dfa.tcpool[c.tags];
            for (const tcmd_t *p = cmd; p; p = p->next) {
                o.cstr("<").str(vartag_name(p->lhs, prefix));
                if (tcmd_t::iscopy(p)) {
                    o.cstr("~").str(vartag_name(p->rhs, prefix));
                }
                o.cstr(">");
            }
            text = o.cstr("\"]").flush();
            append(stmts, code_stmt_text(alc, text));
        }
    }
}

void Go::emit(Output &output, const DFA &dfa, const State *from, CodeStmts *stmts) const
{
    const opt_t *opts = output.block().opts;
    code_alc_t &alc = output.allocator;

    if (type == DOT) {
        info.dot->emit(output, dfa, from, stmts);
        return;
    }

    if (skip && !opts->lookahead) {
        append(stmts, code_stmt_skip(alc));
    }

    gen_settags(output, stmts, dfa, tags, opts->stadfa /* delayed */);

    if (skip && opts->lookahead) {
        append(stmts, code_stmt_skip(alc));
    }

    if (type == SWITCH_IF) {
        append(stmts, info.switchif->emit(output, dfa, from));
    }
    else if (type == BITMAP) {
        append(stmts, info.bitmap->emit(output, dfa, from));
    }
    else if (type == CPGOTO) {
        append(stmts, info.cpgoto->emit(output, dfa, from));
    }
}

} // namespace re2c
