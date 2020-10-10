def swapNum(a, b):
    return b, a

def swapNum2(a, b):
    a = b - a
    b -= a
    a += b
    return a, b

def swapNum3(a, b):
    a = a^b
    b = a^b
    a = a^b
    return a, b

if __name__ == '__main__':
    a, b = swapNum(3, 5)
    print(a, b)
    c, d = swapNum2(3, 5)
    print(c, d)
    e, f = swapNum2(3, 5)
    print(e, f)