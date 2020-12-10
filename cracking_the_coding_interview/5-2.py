def convertToBinary(x):
    digit, tmp, res = 0, 1, 0
    while x > 0:
        if x >= tmp:
            res += 1 / pow(10, digit)
            x -= tmp
        digit += 1
        tmp /= 2
        if digit > 32:
            return "ERROR"
    
    return res

def convertToBinary2(x):
    if x == 1 or x == 0:
        return str(x)
    res = "0."
    r = 1
    while x > 0:
        if len(res) > 34:
            return "ERROR"
        r /= 2
        if x >= r:
            res += "1"
            x -= r
        else:
            res += "0"
    return res


if __name__ == '__main__':
    print(convertToBinary(1))
    print(convertToBinary(0))
    print(convertToBinary(0.5))
    print(convertToBinary(0.25))
    print(convertToBinary(0.75))
    print(convertToBinary(0.3))

    print(convertToBinary2(1))
    print(convertToBinary2(0))
    print(convertToBinary2(0.5))
    print(convertToBinary2(0.25))
    print(convertToBinary2(0.75))
    print(convertToBinary2(0.3))