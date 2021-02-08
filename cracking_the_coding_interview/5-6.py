import unittest

def bit_convertion(a, b):
    mask = 1
    count = 0
    while mask <= max(a, b):
        if (a & mask) != (b & mask):
            count += 1
        mask <<= 1

    return count

def bit_convertion2(a, b):
    c = a ^ b
    count = 0
    while c:
        if c & 1:
            count += 1
        c >>= 1
    return count

class Test(unittest.TestCase):
    def test_simple(self):
        self.assertEqual(bit_convertion(1, 0), 1)
        self.assertEqual(bit_convertion(1, 2), 2)
        self.assertEqual(bit_convertion(29, 15), 2)

    def test_simple2(self):
        self.assertEqual(bit_convertion2(1, 0), 1)
        self.assertEqual(bit_convertion2(1, 2), 2)
        self.assertEqual(bit_convertion2(29, 15), 2)

if __name__ == '__main__':
    unittest.main()