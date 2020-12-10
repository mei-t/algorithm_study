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

if __name__ == '__main__':
    print(convertToBinary(1))
    print(convertToBinary(0))
    print(convertToBinary(0.5))
    print(convertToBinary(0.25))
    print(convertToBinary(0.75))
    print(convertToBinary(0.3))