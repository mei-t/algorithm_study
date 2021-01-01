def add(num1, num2):
    carry = 0
    i = 1
    res = 0
    while num1 > 0 or num2 > 0:
        b1 = num1 & 1
        b2 = num2 & 1
        res += (b1 ^ b2 ^ carry) * i
        carry = (b1 & b2) | (b2 & carry) | (carry & b1)
        num1 = num1 >> 1
        num2 = num2 >> 1
        i = i << 1
    return res

if __name__ == "__main__":
    print(add(2, 5))
    print(add(13, 29))