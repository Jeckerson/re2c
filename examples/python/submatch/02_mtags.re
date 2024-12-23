# re2py $INPUT -o $OUTPUT

NONE = -1

def parse(yyinput):
    yycursor = 0
    %{mtags format = '\n    @@ = []'; %} # autogenerated tag variables

%{
    re2c:YYMTAGP = "@@.append(yycursor)";
    re2c:YYMTAGN = ""; // do nothing
    re2c:yyfill:enable = 0;
    re2c:tags = 1;
    re2c:indent:top = 1;

    num = [0-9]+;

    @t1 num @t2 ("." #t3 num #t4)* [\x00] {
        vers = [int(yyinput[t1:t2])]
        for i in range(len(t3)):
            vers.append(int(yyinput[t3[i]:t4[i]]))
        return vers
    }
    * { return None }
%}

assert parse(b"1\0") == [1]
assert parse(b"1.2.3.4.5.6.7\0") == [1, 2, 3, 4, 5, 6, 7]
assert parse(b"1.2.\0") == None
