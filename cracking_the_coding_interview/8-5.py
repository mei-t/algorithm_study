import unittest

def multiplication(a, b):
    def compute(larger, smaller):
        if smaller == 0:
            return 0

        if smaller == 1:
            return larger

        rest = 0
        if smaller & 1:
            rest += larger
        return compute(larger + larger, smaller >> 1) + rest

    return compute(max(a, b), min(a, b))

class Test(unittest.TestCase):
    def test_simple(self):
        self.assertEqual(multiplication(3, 5), 15)
        self.assertEqual(multiplication(20, 34), 680)
        self.assertEqual(multiplication(0, 2), 0)

if __name__ == '__main__':
    unittest.main()
