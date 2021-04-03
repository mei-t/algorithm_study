import unittest

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

def multiplication(a, b):
    is_minus = (a > 0) ^ (b > 0)
    a = a if a >= 0 else negate(a)
    b = b if b >= 0 else negate(b)
    smaller = min(a, b)
    larger = max(a, b)
    ans = 0
    for _ in range(smaller):
        ans += larger
    return negate(ans) if is_minus else ans
	



class Test(unittest.TestCase):
    def test_negate(self):
        self.assertEqual(negate(10), -10)
        self.assertEqual(negate(-10), 10)
        self.assertEqual(negate(0), 0)
        self.assertEqual(negate(274738), -274738)
        self.assertEqual(negate(-274738), 274738)

if __name__ == '__main__':
    # unittest.main()
    print(multiplication(23, -8372))