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

def my_abs(a):
    return a if a >= 0 else negate(a)

def multiplication(a, b):
    is_minus = (a > 0) ^ (b > 0)
    a = my_abs(a)
    b = my_abs(b)
    smaller = min(a, b)
    larger = max(a, b)
    ans = 0
    for _ in range(smaller):
        ans += larger
    return negate(ans) if is_minus else ans

def division(a, b):
    if b == 0:
        return
    is_minus = (a < 0) ^ (b < 0)
    a = my_abs(a)
    b = my_abs(b)
    ans = 0
    tmp = 0
    while tmp + b <= a:
        tmp += b
        ans += 1
    return negate(ans) if is_minus else ans

class Test(unittest.TestCase):
    def test_negate(self):
        self.assertEqual(negate(10), -10)
        self.assertEqual(negate(-10), 10)
        self.assertEqual(negate(0), 0)
        self.assertEqual(negate(274738), -274738)
        self.assertEqual(negate(-274738), 274738)
    
    def test_minus(self):
        self.assertEqual(minus(50, 2), 48)
        self.assertEqual(minus(50, -2), 52)
        self.assertEqual(minus(50, 0), 50)
        self.assertEqual(minus(-50, -2), -48)
        self.assertEqual(minus(2, 50), -48)
    
    def test_abs(self):
        self.assertEqual(my_abs(10), 10)
        self.assertEqual(my_abs(-10), 10)
        self.assertEqual(my_abs(0), 0)
    
    def test_multiplication(self):
        self.assertEqual(multiplication(2, 3), 6)
        self.assertEqual(multiplication(-2, 3), -6)
        self.assertEqual(multiplication(2, -3), -6)
        self.assertEqual(multiplication(-2, -3), 6)
        self.assertEqual(multiplication(-2, 0), 0)
        self.assertEqual(multiplication(23, -8372), -192556)
    
    def test_division(self):
        self.assertEqual(division(50, 5), 10)
        self.assertEqual(division(50, -5), -10)
        self.assertEqual(division(-50, 5), -10)
        self.assertEqual(division(-50, -5), 10)
        self.assertEqual(division(50, 1), 50)
        self.assertEqual(division(234, 6), 39)
        self.assertEqual(division(50, 4), 12)


if __name__ == '__main__':
    unittest.main()