/* Generated by re2c */
#line 1 "conditions/condtype_forwdecl.re"
// re2c $INPUT -o $OUTPUT -cs
enum cond_t : int;

int main ()
{
	cond_t cond;
	char * YYCURSOR;
#define YYGETCONDITION() cond

#line 13 "conditions/condtype_forwdecl.c"
{
	unsigned char yych;
	if (YYGETCONDITION() < 1) goto yyc_a;
	else goto yyc_b;
/* *********************************** */
yyc_a:
	yych = *YYCURSOR;
	if (yych == 'a') goto yy1;
yy1:
	++YYCURSOR;
#line 13 "conditions/condtype_forwdecl.re"
	{}
#line 26 "conditions/condtype_forwdecl.c"
/* *********************************** */
yyc_b:
	yych = *YYCURSOR;
	if (yych == 'b') goto yy3;
yy3:
	++YYCURSOR;
#line 14 "conditions/condtype_forwdecl.re"
	{}
#line 35 "conditions/condtype_forwdecl.c"
}
#line 15 "conditions/condtype_forwdecl.re"

	return 0;
}

#line 42 "conditions/condtype_forwdecl.c"
enum cond_t : int {
	yyca,
	yycb
};
#line 19 "conditions/condtype_forwdecl.re"

conditions/condtype_forwdecl.re:9:0: warning: control flow in condition 'a' is undefined for strings that match '[\x0-\x60\x62-\xFF]', use default rule '*' [-Wundefined-control-flow]
conditions/condtype_forwdecl.re:9:0: warning: control flow in condition 'b' is undefined for strings that match '[\x0-\x61\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
