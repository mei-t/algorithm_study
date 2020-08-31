import unittest

def insert(n, m, i, j):
    top = (~0) << (i + 1)
    bottom = (1 << j) - 1
    mask = ~(top & bottom)
    return (n & mask) | (m << i)

class Test(unittest.TestCase):
    def test_simple(self):
        self.assertEqual(insert(0b10000000000, 0b10011, 2, 6), 0b10001001100)

if __name__ == '__main__':
    unittest.main()