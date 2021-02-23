import unittest

def exchange_bit_pair(input):
    tmp = input
    even_mask, odd_mask = 0, 0
    while tmp:
        even_mask <<= 2
        odd_mask <<= 2
        even_mask |= 1
        odd_mask |= 2
        tmp >>= 2
    return ((input & even_mask) << 1) | ((input & odd_mask) >> 1)

class Test(unittest.TestCase):
    def test_simple(self):
        self.assertEquals(exchange_bit_pair(1), 2)
        self.assertEquals(exchange_bit_pair(10), 5)
        self.assertEquals(exchange_bit_pair(int('1101001', 2)), int('10010110', 2))

if __name__ == '__main__':
    unittest.main()
