#line 1 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
#include "ragel/common.c"

const char *delim = "\n";


#line 17 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"



#line 12 "gen/ragel/cat2_8.c"
static const int abcd_start = 28;
static const int abcd_first_final = 28;
static const int abcd_error = 0;

static const int abcd_en_main = 28;


#line 19 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"


static void lex(Input *in, Output *out)
{
	char *p = in->p;
	char *pe = in->pe;
	const char
	*a0, *a1,
	*b0, *b1;
	int cs;
	
	
#line 33 "gen/ragel/cat2_8.c"
	{
		cs = (int)abcd_start;
	}
	
#line 30 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
	
	
#line 41 "gen/ragel/cat2_8.c"
	{
		if ( p == pe )
			goto _test_eof;
		switch ( cs ) {
			case 28:
			goto st_case_28;
			case 0:
			goto st_case_0;
			case 1:
			goto st_case_1;
			case 2:
			goto st_case_2;
			case 3:
			goto st_case_3;
			case 4:
			goto st_case_4;
			case 5:
			goto st_case_5;
			case 6:
			goto st_case_6;
			case 7:
			goto st_case_7;
			case 8:
			goto st_case_8;
			case 9:
			goto st_case_9;
			case 10:
			goto st_case_10;
			case 11:
			goto st_case_11;
			case 12:
			goto st_case_12;
			case 13:
			goto st_case_13;
			case 14:
			goto st_case_14;
			case 15:
			goto st_case_15;
			case 16:
			goto st_case_16;
			case 17:
			goto st_case_17;
			case 18:
			goto st_case_18;
			case 19:
			goto st_case_19;
			case 20:
			goto st_case_20;
			case 21:
			goto st_case_21;
			case 22:
			goto st_case_22;
			case 23:
			goto st_case_23;
			case 24:
			goto st_case_24;
			case 25:
			goto st_case_25;
			case 26:
			goto st_case_26;
			case 27:
			goto st_case_27;
		}
		goto st_out;
		_ctr33:
		{
#line 11 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			
			outs(out, a0, b0); outc(out, '.'); outs(out, b0, a1); outc(out, '.');
			outs(out, a1, b1); outc(out, '.'); outs(out, b1, p + 1);
		}
		
#line 114 "gen/ragel/cat2_8.c"
		
		goto _st28;
		_st28:
		p+= 1;
		if ( p == pe )
			goto _test_eof28;
		st_case_28:
		if ( ( (*( p))) == 97 ) {
			goto _ctr53;
		}
		{
			goto _st0;
		}
		st_case_0:
		_st0:
		cs = 0;
		goto _pop;
		_ctr53:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a0 = p; }
		
#line 137 "gen/ragel/cat2_8.c"
		
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 143 "gen/ragel/cat2_8.c"
		
		goto _st1;
		_st1:
		p+= 1;
		if ( p == pe )
			goto _test_eof1;
		st_case_1:
		if ( ( (*( p))) == 97 ) {
			goto _ctr2;
		}
		{
			goto _st0;
		}
		_ctr2:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 162 "gen/ragel/cat2_8.c"
		
		goto _st2;
		_st2:
		p+= 1;
		if ( p == pe )
			goto _test_eof2;
		st_case_2:
		if ( ( (*( p))) == 97 ) {
			goto _ctr4;
		}
		{
			goto _st0;
		}
		_ctr4:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 181 "gen/ragel/cat2_8.c"
		
		goto _st3;
		_st3:
		p+= 1;
		if ( p == pe )
			goto _test_eof3;
		st_case_3:
		if ( ( (*( p))) == 97 ) {
			goto _ctr6;
		}
		{
			goto _st0;
		}
		_ctr6:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 200 "gen/ragel/cat2_8.c"
		
		goto _st4;
		_st4:
		p+= 1;
		if ( p == pe )
			goto _test_eof4;
		st_case_4:
		if ( ( (*( p))) == 97 ) {
			goto _ctr8;
		}
		{
			goto _st0;
		}
		_ctr8:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 219 "gen/ragel/cat2_8.c"
		
		goto _st5;
		_st5:
		p+= 1;
		if ( p == pe )
			goto _test_eof5;
		st_case_5:
		if ( ( (*( p))) == 97 ) {
			goto _ctr10;
		}
		{
			goto _st0;
		}
		_ctr10:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 238 "gen/ragel/cat2_8.c"
		
		goto _st6;
		_st6:
		p+= 1;
		if ( p == pe )
			goto _test_eof6;
		st_case_6:
		if ( ( (*( p))) == 97 ) {
			goto _ctr12;
		}
		{
			goto _st0;
		}
		_ctr12:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 257 "gen/ragel/cat2_8.c"
		
		goto _st7;
		_st7:
		p+= 1;
		if ( p == pe )
			goto _test_eof7;
		st_case_7:
		if ( ( (*( p))) == 97 ) {
			goto _ctr14;
		}
		{
			goto _st0;
		}
		_ctr14:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 276 "gen/ragel/cat2_8.c"
		
		goto _st8;
		_st8:
		p+= 1;
		if ( p == pe )
			goto _test_eof8;
		st_case_8:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr16;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		_ctr16:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 300 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 306 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 312 "gen/ragel/cat2_8.c"
		
		goto _st9;
		_st9:
		p+= 1;
		if ( p == pe )
			goto _test_eof9;
		st_case_9:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr19;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		_ctr19:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 336 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 342 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 348 "gen/ragel/cat2_8.c"
		
		goto _st10;
		_st10:
		p+= 1;
		if ( p == pe )
			goto _test_eof10;
		st_case_10:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr21;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		_ctr21:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 372 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 378 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 384 "gen/ragel/cat2_8.c"
		
		goto _st11;
		_st11:
		p+= 1;
		if ( p == pe )
			goto _test_eof11;
		st_case_11:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr23;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		_ctr23:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 408 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 414 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 420 "gen/ragel/cat2_8.c"
		
		goto _st12;
		_st12:
		p+= 1;
		if ( p == pe )
			goto _test_eof12;
		st_case_12:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr25;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		_ctr25:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 444 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 450 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 456 "gen/ragel/cat2_8.c"
		
		goto _st13;
		_st13:
		p+= 1;
		if ( p == pe )
			goto _test_eof13;
		st_case_13:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr27;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		_ctr27:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 480 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 486 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 492 "gen/ragel/cat2_8.c"
		
		goto _st14;
		_st14:
		p+= 1;
		if ( p == pe )
			goto _test_eof14;
		st_case_14:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr29;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		_ctr29:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 516 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 522 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 528 "gen/ragel/cat2_8.c"
		
		goto _st15;
		_st15:
		p+= 1;
		if ( p == pe )
			goto _test_eof15;
		st_case_15:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr31;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		_ctr31:
		{
#line 9 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b0 = p; }
		
#line 552 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 558 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 564 "gen/ragel/cat2_8.c"
		
		goto _st16;
		_st16:
		p+= 1;
		if ( p == pe )
			goto _test_eof16;
		st_case_16:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr33;
			}
			case 97: {
				goto _ctr31;
			}
			case 98: {
				goto _st17;
			}
		}
		{
			goto _st0;
		}
		_st17:
		p+= 1;
		if ( p == pe )
			goto _test_eof17;
		st_case_17:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr33;
			}
			case 97: {
				goto _ctr35;
			}
			case 98: {
				goto _st17;
			}
		}
		{
			goto _st0;
		}
		_ctr35:
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			a1 = p; }
		
#line 610 "gen/ragel/cat2_8.c"
		
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 616 "gen/ragel/cat2_8.c"
		
		goto _st18;
		_st18:
		p+= 1;
		if ( p == pe )
			goto _test_eof18;
		st_case_18:
		if ( ( (*( p))) == 97 ) {
			goto _ctr37;
		}
		{
			goto _st0;
		}
		_ctr37:
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 635 "gen/ragel/cat2_8.c"
		
		goto _st19;
		_st19:
		p+= 1;
		if ( p == pe )
			goto _test_eof19;
		st_case_19:
		if ( ( (*( p))) == 97 ) {
			goto _ctr39;
		}
		{
			goto _st0;
		}
		_ctr39:
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 654 "gen/ragel/cat2_8.c"
		
		goto _st20;
		_st20:
		p+= 1;
		if ( p == pe )
			goto _test_eof20;
		st_case_20:
		if ( ( (*( p))) == 97 ) {
			goto _ctr41;
		}
		{
			goto _st0;
		}
		_ctr41:
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 673 "gen/ragel/cat2_8.c"
		
		goto _st21;
		_st21:
		p+= 1;
		if ( p == pe )
			goto _test_eof21;
		st_case_21:
		if ( ( (*( p))) == 97 ) {
			goto _ctr43;
		}
		{
			goto _st0;
		}
		_ctr43:
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 692 "gen/ragel/cat2_8.c"
		
		goto _st22;
		_st22:
		p+= 1;
		if ( p == pe )
			goto _test_eof22;
		st_case_22:
		if ( ( (*( p))) == 97 ) {
			goto _ctr45;
		}
		{
			goto _st0;
		}
		_ctr45:
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 711 "gen/ragel/cat2_8.c"
		
		goto _st23;
		_st23:
		p+= 1;
		if ( p == pe )
			goto _test_eof23;
		st_case_23:
		if ( ( (*( p))) == 97 ) {
			goto _ctr47;
		}
		{
			goto _st0;
		}
		_ctr47:
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 730 "gen/ragel/cat2_8.c"
		
		goto _st24;
		_st24:
		p+= 1;
		if ( p == pe )
			goto _test_eof24;
		st_case_24:
		if ( ( (*( p))) == 97 ) {
			goto _ctr49;
		}
		{
			goto _st0;
		}
		_ctr49:
		{
#line 10 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
			b1 = p; }
		
#line 749 "gen/ragel/cat2_8.c"
		
		goto _st25;
		_st25:
		p+= 1;
		if ( p == pe )
			goto _test_eof25;
		st_case_25:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr33;
			}
			case 97: {
				goto _ctr49;
			}
			case 98: {
				goto _st26;
			}
		}
		{
			goto _st0;
		}
		_st26:
		p+= 1;
		if ( p == pe )
			goto _test_eof26;
		st_case_26:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr33;
			}
			case 98: {
				goto _st26;
			}
		}
		{
			goto _st0;
		}
		_st27:
		p+= 1;
		if ( p == pe )
			goto _test_eof27;
		st_case_27:
		switch( ( (*( p))) ) {
			case 97: {
				goto _ctr35;
			}
			case 98: {
				goto _st27;
			}
		}
		{
			goto _st0;
		}
		st_out:
		_test_eof28: cs = 28; goto _test_eof; 
		_test_eof1: cs = 1; goto _test_eof; 
		_test_eof2: cs = 2; goto _test_eof; 
		_test_eof3: cs = 3; goto _test_eof; 
		_test_eof4: cs = 4; goto _test_eof; 
		_test_eof5: cs = 5; goto _test_eof; 
		_test_eof6: cs = 6; goto _test_eof; 
		_test_eof7: cs = 7; goto _test_eof; 
		_test_eof8: cs = 8; goto _test_eof; 
		_test_eof9: cs = 9; goto _test_eof; 
		_test_eof10: cs = 10; goto _test_eof; 
		_test_eof11: cs = 11; goto _test_eof; 
		_test_eof12: cs = 12; goto _test_eof; 
		_test_eof13: cs = 13; goto _test_eof; 
		_test_eof14: cs = 14; goto _test_eof; 
		_test_eof15: cs = 15; goto _test_eof; 
		_test_eof16: cs = 16; goto _test_eof; 
		_test_eof17: cs = 17; goto _test_eof; 
		_test_eof18: cs = 18; goto _test_eof; 
		_test_eof19: cs = 19; goto _test_eof; 
		_test_eof20: cs = 20; goto _test_eof; 
		_test_eof21: cs = 21; goto _test_eof; 
		_test_eof22: cs = 22; goto _test_eof; 
		_test_eof23: cs = 23; goto _test_eof; 
		_test_eof24: cs = 24; goto _test_eof; 
		_test_eof25: cs = 25; goto _test_eof; 
		_test_eof26: cs = 26; goto _test_eof; 
		_test_eof27: cs = 27; goto _test_eof; 
		
		_test_eof: {}
		if ( cs >= 28 )
			goto _out; _pop: {}
		_out: {}
	}
	
#line 31 "../../../benchmarks/submatch_dfa_aot/src/ragel/cat2_8.rl"
	
	
	in->p = p;
	in->pe = pe;
}