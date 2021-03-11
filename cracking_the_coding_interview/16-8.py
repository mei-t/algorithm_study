ones_place_map = {
    1: 'One',
    2: 'Two',
    3: 'Three',
    4: 'Four',
    5: 'Five',
    6: 'Six',
    7: 'Seven',
    8: 'Eight',
    9: 'Nine'
}

tens_place_map = {
    10: 'Ten',
    20: 'Twenty',
    30: 'Thirty',
    40: 'Fourty',
    50: 'Fifty',
    60: 'Sixty',
    70: 'Seventy',
    80: 'Eighty',
    90: 'Ninety'
}

ten_to_twenty_map = {
    11: 'Eleven',
    12: 'Twelve',
    13: 'Thirteen',
    14: 'Fourteen',
    15: 'Fifteen',
    16: 'Sixteen',
    17: 'Seventeen',
    18: 'Eighteen',
    19: 'Nineteen'
}

digit_map = {
    1: 'Thousand',
    2: 'Million',
    3: 'Billion'
}

def english_number(num):
    s = []
    is_negative = True if num < 0 else False
    if num == 0:
        return 'Zero'
    
    num = abs(num)
    digit = 0
    while num > 0:
        if digit > 0:
            s.append(digit_map[digit])
        op = num % 10
        tp = num % 100 - op
        hp = num % 1000 - tp - op
        if 10 < op + tp < 20:
            s.append(ten_to_twenty_map[op + tp])
        else:
            if op > 0:
                s.append(ones_place_map[op])
            if tp > 0:
                s.append(tens_place_map[tp])
        if hp > 0:
            s.append(ones_place_map[hp // 100] + ' Hundred')
        num //= 1000
        digit += 1
    
    res = ' '.join(reversed(s))
    if is_negative:
        return 'Minus ' + res
    return res

if __name__ == '__main__':
    print(english_number(12345678))