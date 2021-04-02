def negate(a):
    new_sign = -1 if a > 0 else 1
    ans = 0
    delta = new_sign
    while a != 0:
        def_sign = (a > 0) ^ (a + delta > 0)
        if a + delta != 0 and def_sign:
            delta = new_sign
        ans += delta
        a += delta
        delta += delta
    return ans

def minus(a, b):
    return a + negate(b)

if __name__ == '__main__':
    print(negate(-10))