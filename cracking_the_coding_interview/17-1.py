import unittest

def add1(num1, num2):
    carry = 0
    i = 1
    res = 0
    while num1 > 0 or num2 > 0 or carry:
        b1 = num1 & 1
        b2 = num2 & 1
        res += (b1 ^ b2 ^ carry) * i
        carry = (b1 & b2) | (b2 & carry) | (carry & b1)
        num1 = num1 >> 1
        num2 = num2 >> 1
        i = i << 1
    return res

def add2(num1, num2):
    if num2 == 0:
        return num1

    res = num1 ^ num2
    carry = (num1 & num2) << 1
    return add2(res, carry)

class Test(unittest.TestCase):

    def test_add1(self):
        self.assertEqual(add1(2, 5), 7)
        self.assertEqual(add1(13, 29), 42)

    def test_add2(self):
        self.assertEqual(add2(2, 5), 7)
        self.assertEqual(add2(13, 29), 42)

if __name__ == "__main__":
    unittest.main()