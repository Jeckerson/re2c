/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'a':	goto yy3;
	case 'x':	goto yy5;
	default:	goto yy2;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	yych = *++YYCURSOR;
	yyt1 = yyt2 = YYCURSOR - 1;
	switch (yych) {
	case 'a':	goto yy7;
	case 'x':	goto yy9;
	default:	goto yy4;
	}
yy4:
	YYCURSOR = YYMARKER;
	goto yy2;
yy5:
	++YYCURSOR;
	yyt1 = yyt2 = yyt3 = YYCURSOR - 1;
yy6:
	yynmatch = 3;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt2;
	yypmatch[3] = yyt3;
	yypmatch[1] = YYCURSOR;
	yypmatch[4] = YYCURSOR - 1;
	yypmatch[5] = YYCURSOR;
	{}
yy7:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy7;
	case 'x':	goto yy9;
	default:	goto yy4;
	}
yy9:
	++YYCURSOR;
	yyt3 = YYCURSOR - 1;
	goto yy6;
}

posix_captures/nullsubexpr/15.i--flex-syntax--stadfa.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]