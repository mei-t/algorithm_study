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

class Test(unittest.TestCase):
    def test_negate(self):
        self.assertEqual(negate(10), -10)
        self.assertEqual(negate(-10), 10)
        self.assertEqual(negate(0), 0)
        self.assertEqual(negate(274738), -274738)
        self.assertEqual(negate(-274738), 274738)

if __name__ == '__main__':
    unittest.main()