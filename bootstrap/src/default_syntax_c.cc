const char* DEFAULT_SYNTAX_C =
    "api = [pointers, generic];\n"
    "api_style = [functions, freeform];\n"
    "jump_model = [goto_label, loop_switch];\n"
    "target = [code, dot, skeleton];\n"
    "\n"
    "computed_goto = optional;\n"
    "case_ranges = optional;\n"
    "constants = snake_case;\n"
    "char_literals = (encoding.ebcdic ? hexadecimal : symbolic);\n"
    "semicolons = yes;\n"
    "abort_requires_include = yes;\n"
    "\n"
    "code:var = topindent type \" \" name (have_init? \" = \" init) \";\" nl;\n"
    "\n"
    "code:const = topindent \"#define \" name \" \" init nl;\n"
    "\n"
    "code:array =\n"
    "    topindent type \" \" name \"[\" size \"] = {\" nl indent\n"
    "        [row{0:-2}: topindent [elem{0:-2}: elem \", \"] [elem{-1}: elem \",\"] nl]\n"
    "        [row{-1}:   topindent [elem{0:-2}: elem \", \"] [elem{-1}: elem]     nl]\n"
    "    dedent topindent \"};\" nl;\n"
    "\n"
    "code:type_int = \"int\";\n"
    "code:type_uint = \"unsigned int\";\n"
    "code:type_yybm = \"static const unsigned char\";\n"
    "//code:type_yytarget = \"static const void*\";\n"
    "\n"
    "code:if_then_else =\n"
    "    topindent \"if (\" then_cond \") {\" nl\n"
    "        indent [then_stmt: then_stmt] dedent\n"
    "    (have_else_part? topindent \"} else \" (have_else_cond? \"if (\" else_cond \") \") \"{\" nl\n"
    "        indent [else_stmt: else_stmt] dedent)\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:if_then_oneline = topindent \"if (\" then_cond \") \" [then_stmt: then_stmt];\n"
    "\n"
    "code:switch =\n"
    "    topindent \"switch (\" expr \") {\" nl\n"
    "        indent [case: case] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch_cases =\n"
    "    [case: case nl]\n"
    "        indent [stmt: stmt] dedent;\n"
    "\n"
    "code:switch_cases_oneline =\n"
    "    [case{0:-2}: case nl]\n"
    "    [case{-1}:   case \" \" [stmt: stmt]];\n"
    "\n"
    "code:switch_case_range = (case_ranges\n"
    "    ? topindent \"case \" [val{0}: val] (multival ? \" ... \" [val{-1}: val]) \":\"\n"
    "    : [val{0:-2}: topindent \"case \" val \":\" nl]\n"
    "      [val{-1}:   topindent \"case \" val \":\"]);\n"
    "\n"
    "code:switch_case_default =\n"
    "    topindent \"default:\";\n"
    "\n"
    "code:loop =\n"
    "    topindent \"for (;;) {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:cond_enum =\n"
    "    \"enum \" name \" {\" nl\n"
    "        [elem{0:-2}: indent elem (jump_model.loop_switch? \" = \" init) \",\" nl]\n"
    "        [elem{-1}:   indent elem (jump_model.loop_switch? \" = \" init) nl]\n"
    "    \"};\" nl;\n"
    "\n"
    "code:autogen_comment = \"/* Generated by re2c\" (version? \" \" version) (date? \" on \" date) \" */\";\n"
    "\n"
    "code:line_directive = \"#line \" line \" \\\"\" file \"\\\"\" nl;\n"
    "\n"
    "code:label = name;\n"
    "\n"
    "code:bitmap_check = table \"[\" offset \" + \" char \"] & \" mask;\n"
    "\n"
    "code:abort_expr = \"abort()\";\n"
    "\n"
    "code:yypeek_expr = (api.generic\n"
    "    ? expr (api_style.functions ? \"()\")\n"
    "    : \"*\" expr );\n"
    ;
