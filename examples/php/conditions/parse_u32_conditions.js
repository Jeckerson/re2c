// Generated by re2js
// re2js $INPUT -o $OUTPUT -c

const YYC_INIT = 0
const YYC_BIN = 10
const YYC_OCT = 13
const YYC_DEC = 16
const YYC_HEX = 19


function parse_u32(yyinput) {
    let yycursor = 0
    let yycond = YYC_INIT
    let n = 0

    loop: while (true) {
    
        {
            let yych = 0
            let yystate = yycond
            yyl: while (true) {
                switch (yystate) {
                    case 0:
                        yych = yyinput.charCodeAt(yycursor)
                        yycursor += 1;
                        switch (yych) {
                            case 0x30:
                                yystate = 2
                                continue yyl
                            case 0x31:
                            case 0x32:
                            case 0x33:
                            case 0x34:
                            case 0x35:
                            case 0x36:
                            case 0x37:
                            case 0x38:
                            case 0x39:
                                yystate = 4
                                continue yyl
                            default:
                                yystate = 1
                                continue yyl
                        }
                    case 1:
                        { return null }
                    case 2:
                        yymarker = yycursor;
                        yych = yyinput.charCodeAt(yycursor)
                        switch (yych) {
                            case 0x42:
                            case 0x62:
                                yycursor += 1;
                                yystate = 5
                                continue yyl
                            case 0x58:
                            case 0x78:
                                yycursor += 1;
                                yystate = 7
                                continue yyl
                            default:
                                yystate = 3
                                continue yyl
                        }
                    case 3:
                        yycond = YYC_OCT;
                        yystate = YYC_OCT
                        continue yyl
                    case 4:
                        yycursor -= 1;
                        yycond = YYC_DEC;
                        yystate = YYC_DEC
                        continue yyl
                    case 5:
                        yych = yyinput.charCodeAt(yycursor)
                        switch (yych) {
                            case 0x30:
                            case 0x31:
                                yycursor += 1;
                                yystate = 8
                                continue yyl
                            default:
                                yystate = 6
                                continue yyl
                        }
                    case 6:
                        yycursor = yymarker;
                        yystate = 3
                        continue yyl
                    case 7:
                        yych = yyinput.charCodeAt(yycursor)
                        switch (yych) {
                            case 0x30:
                            case 0x31:
                            case 0x32:
                            case 0x33:
                            case 0x34:
                            case 0x35:
                            case 0x36:
                            case 0x37:
                            case 0x38:
                            case 0x39:
                            case 0x41:
                            case 0x42:
                            case 0x43:
                            case 0x44:
                            case 0x45:
                            case 0x46:
                            case 0x61:
                            case 0x62:
                            case 0x63:
                            case 0x64:
                            case 0x65:
                            case 0x66:
                                yycursor += 1;
                                yystate = 9
                                continue yyl
                            default:
                                yystate = 6
                                continue yyl
                        }
                    case 8:
                        yycursor -= 1;
                        yycond = YYC_BIN;
                        yystate = YYC_BIN
                        continue yyl
                    case 9:
                        yycursor -= 1;
                        yycond = YYC_HEX;
                        yystate = YYC_HEX
                        continue yyl
                    case 10:
                        yych = yyinput.charCodeAt(yycursor)
                        yycursor += 1;
                        switch (yych) {
                            case 0x30:
                            case 0x31:
                                yystate = 12
                                continue yyl
                            default:
                                yystate = 11
                                continue yyl
                        }
                    case 11:
                        { return n }
                    case 12:
                        { n = n * 2 + (yyinput.charCodeAt(yycursor - 1) - 48); continue loop }
                    case 13:
                        yych = yyinput.charCodeAt(yycursor)
                        yycursor += 1;
                        switch (yych) {
                            case 0x30:
                            case 0x31:
                            case 0x32:
                            case 0x33:
                            case 0x34:
                            case 0x35:
                            case 0x36:
                            case 0x37:
                                yystate = 15
                                continue yyl
                            default:
                                yystate = 14
                                continue yyl
                        }
                    case 14:
                        { return n }
                    case 15:
                        { n = n * 8 + (yyinput.charCodeAt(yycursor - 1) - 48); continue loop }
                    case 16:
                        yych = yyinput.charCodeAt(yycursor)
                        yycursor += 1;
                        switch (yych) {
                            case 0x30:
                            case 0x31:
                            case 0x32:
                            case 0x33:
                            case 0x34:
                            case 0x35:
                            case 0x36:
                            case 0x37:
                            case 0x38:
                            case 0x39:
                                yystate = 18
                                continue yyl
                            default:
                                yystate = 17
                                continue yyl
                        }
                    case 17:
                        { return n }
                    case 18:
                        { n = n * 10 + (yyinput.charCodeAt(yycursor - 1) - 48); continue loop }
                    case 19:
                        yych = yyinput.charCodeAt(yycursor)
                        yycursor += 1;
                        switch (yych) {
                            case 0x30:
                            case 0x31:
                            case 0x32:
                            case 0x33:
                            case 0x34:
                            case 0x35:
                            case 0x36:
                            case 0x37:
                            case 0x38:
                            case 0x39:
                                yystate = 21
                                continue yyl
                            case 0x41:
                            case 0x42:
                            case 0x43:
                            case 0x44:
                            case 0x45:
                            case 0x46:
                                yystate = 22
                                continue yyl
                            case 0x61:
                            case 0x62:
                            case 0x63:
                            case 0x64:
                            case 0x65:
                            case 0x66:
                                yystate = 23
                                continue yyl
                            default:
                                yystate = 20
                                continue yyl
                        }
                    case 20:
                        { return n }
                    case 21:
                        { n = n * 16 + (yyinput.charCodeAt(yycursor - 1) - 48); continue loop }
                    case 22:
                        { n = n * 16 + (yyinput.charCodeAt(yycursor - 1) - 55); continue loop }
                    case 23:
                        { n = n * 16 + (yyinput.charCodeAt(yycursor - 1) - 87); continue loop }
                    default:
                        throw "internal lexer error"
                }
            }
        }

    }
}

function test(s, n) {
    if (parse_u32(s) != n) throw "error!"
}

test("\0", null)
test("1234567890\0", 1234567890)
test("0b1101\0", 13)
test("0x7Fe\0", 2046)
test("0644\0", 420)
test("9999999999\0", 9999999999)
