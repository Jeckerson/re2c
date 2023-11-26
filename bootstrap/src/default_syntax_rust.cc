const char* DEFAULT_SYNTAX_RUST =
    "api = [generic];\n"
    "api_style = [freeform, functions];\n"
    "jump_model = [loop_switch];\n"
    "target = [code, dot];\n"
    "\n"
    "computed_goto = unsupported;\n"
    "case_ranges = unsupported;\n"
    "constants = snake_case;\n"
    "char_literals = (encoding.ebcdic ? hexadecimal : symbolic);\n"
    "semicolons = yes;\n"
    "label_indent = default;\n"
    "abort_requires_include = no;\n"
    "\n"
    "code:if_then_else =\n"
    "    \"if \" then_cond \" {\" nl\n"
    "        [then_stmt: indent then_stmt nl]\n"
    "    (have_else_part? \"} else \" (have_else_cond? \"if \" else_cond \" \") \"{\" nl\n"
    "        [else_stmt: indent else_stmt nl])\n"
    "    \"}\" nl;\n"
    "\n"
    "code:var_defn_local =\n"
    "    (have_init? \"\" : \"#[allow(unused_assignments)]\" nl)\n"
    "    \"let mut \" name \" : \" type \" = \" (have_init? init : \"0\") nl;\n"
    "code:var_defn_global = \"const \" name \": \" type \" = \" init nl;\n"
    "// code:array_defn = ??;\n"
    "\n"
    "code:type_int = \"isize\";\n"
    "code:type_uint = \"usize\";\n"
    "code:type_yyctype = type;\n"
    "// code:type_yybm = ??;\n"
    "\n"
    "code:switch =\n"
    "    topindent \"match \" expr \" {\" nl\n"
    "        indent [case: case] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch_cases =\n"
    "    [case{0:-2}: topindent case \" |\" nl]\n"
    "    [case{-1}:   topindent case \" => {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl];\n"
    "\n"
    "code:switch_cases_oneline =\n"
    "    [case{0:-2}: topindent case \" |\" nl]\n"
    "    [case{-1}:   topindent case \" => \" [stmt: stmt]];\n"
    "\n"
    "code:switch_case_range = [val{0}: val] (multival ? \" ..= \" [val{-1}: val]);\n"
    "\n"
    "code:switch_case_default = \"_\";\n"
    "\n"
    "code:loop =\n"
    "    (have_label? label \": \") \"loop {\" nl\n"
    "        [stmt: indent stmt nl]\n"
    "    \"}\" nl;\n"
    "\n"
    "code:cond_enum = [elem: \"const \" elem \": \" (storable_state? \"isize\" : \"usize\") \" = \" init \";\" nl];\n"
    "\n"
    "code:autogen_comment = \"/* Generated by re2c\" (version? \" \" version) (date? \" on \" date) \" */\";\n"
    "\n"
    "// code:line_directive (no line directives in Rust)\n"
    "\n"
    "code:label = \"'\" name;\n"
    "\n"
    "// code:bitmap_check (bitmaps not supported in Rust)\n"
    "\n"
    "code:abort_expr = \"panic!(\\\"internal lexer error\\\")\";\n"
    "\n"
    "code:yypeek_expr = (unsafe? \"unsafe { \" expr \" }\" : expr) (api_style.functions ? \"()\");\n"
    ;
