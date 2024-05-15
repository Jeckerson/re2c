# Generated by re2c
# re2py $INPUT -o $OUTPUT -c

YYC_INIT = 0
YYC_BIN = 10
YYC_OCT = 13
YYC_DEC = 16
YYC_HEX = 19


def parse_u32(str):
    cur = 0
    cond = YYC_INIT
    num = 0

    while True:
    
        yystate = cond
        while True:
            match yystate:
                case 0:
                    yych = str[cur]
                    cur += 1
                    if yych <= 0x2F:
                        yystate = 1
                        continue
                    if yych <= 0x30:
                        yystate = 2
                        continue
                    if yych <= 0x39:
                        yystate = 4
                        continue
                    yystate = 1
                    continue
                case 1:
                    return None
                case 2:
                    mar = cur
                    yych = str[cur]
                    if yych <= 0x58:
                        if yych == 0x42:
                            cur += 1
                            yystate = 5
                            continue
                        if yych >= 0x58:
                            cur += 1
                            yystate = 7
                            continue
                        yystate = 3
                        continue
                    else:
                        if yych <= 0x62:
                            if yych >= 0x62:
                                cur += 1
                                yystate = 5
                                continue
                            yystate = 3
                            continue
                        else:
                            if yych == 0x78:
                                cur += 1
                                yystate = 7
                                continue
                            yystate = 3
                            continue
                case 3:
                    cond = YYC_OCT
                    yystate = YYC_OCT
                    continue
                case 4:
                    cur += -1
                    cond = YYC_DEC
                    yystate = YYC_DEC
                    continue
                case 5:
                    yych = str[cur]
                    if yych <= 0x2F:
                        yystate = 6
                        continue
                    if yych <= 0x31:
                        cur += 1
                        yystate = 8
                        continue
                    yystate = 6
                    continue
                case 6:
                    cur = mar
                    yystate = 3
                    continue
                case 7:
                    yych = str[cur]
                    if yych <= 0x40:
                        if yych <= 0x2F:
                            yystate = 6
                            continue
                        if yych <= 0x39:
                            cur += 1
                            yystate = 9
                            continue
                        yystate = 6
                        continue
                    else:
                        if yych <= 0x46:
                            cur += 1
                            yystate = 9
                            continue
                        if yych <= 0x60:
                            yystate = 6
                            continue
                        if yych <= 0x66:
                            cur += 1
                            yystate = 9
                            continue
                        yystate = 6
                        continue
                case 8:
                    cur += -1
                    cond = YYC_BIN
                    yystate = YYC_BIN
                    continue
                case 9:
                    cur += -1
                    cond = YYC_HEX
                    yystate = YYC_HEX
                    continue
                case 10:
                    yych = str[cur]
                    cur += 1
                    if yych <= 0x2F:
                        yystate = 11
                        continue
                    if yych <= 0x31:
                        yystate = 12
                        continue
                    yystate = 11
                    continue
                case 11:
                    return num
                case 12:
                    num = num * 2 + (str[cur - 1] - 48)
                    break
                case 13:
                    yych = str[cur]
                    cur += 1
                    if yych <= 0x2F:
                        yystate = 14
                        continue
                    if yych <= 0x37:
                        yystate = 15
                        continue
                    yystate = 14
                    continue
                case 14:
                    return num
                case 15:
                    num = num * 8 + (str[cur - 1] - 48)
                    break
                case 16:
                    yych = str[cur]
                    cur += 1
                    if yych <= 0x2F:
                        yystate = 17
                        continue
                    if yych <= 0x39:
                        yystate = 18
                        continue
                    yystate = 17
                    continue
                case 17:
                    return num
                case 18:
                    num = num * 10 + (str[cur - 1] - 48)
                    break
                case 19:
                    yych = str[cur]
                    cur += 1
                    if yych <= 0x40:
                        if yych <= 0x2F:
                            yystate = 20
                            continue
                        if yych <= 0x39:
                            yystate = 21
                            continue
                        yystate = 20
                        continue
                    else:
                        if yych <= 0x46:
                            yystate = 22
                            continue
                        if yych <= 0x60:
                            yystate = 20
                            continue
                        if yych <= 0x66:
                            yystate = 23
                            continue
                        yystate = 20
                        continue
                case 20:
                    return num
                case 21:
                    num = num * 16 + (str[cur - 1] - 48)
                    break
                case 22:
                    num = num * 16 + (str[cur - 1] - 55)
                    break
                case 23:
                    num = num * 16 + (str[cur - 1] - 87)
                    break
                case _:
                    raise "internal lexer error"


assert parse_u32(b"\0") == None
assert parse_u32(b"1234567890\0") == 1234567890
assert parse_u32(b"0b1101\0") == 13
assert parse_u32(b"0x7Fe\0") == 2046
assert parse_u32(b"0644\0") == 420
assert parse_u32(b"9999999999\0") == 9999999999