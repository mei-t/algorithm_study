def count_two(n):
    res = 0
    digit = 1
    prev = 0
    while n:
        res += (n // 10 + int((n % 10) > 2)) * digit + int(n % 10 == 2) * (prev + 1)
        prev += (n % 10) * digit
        digit *= 10
        n //= 10
    return res

if __name__ == '__main__':
    res = count_two(223)
    print(res)
