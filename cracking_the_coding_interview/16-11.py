import unittest

def diving_board(shorter, longer, k):
    res = [shorter * i + longer * (k - i) for i in range(k + 1)]
    return res

class Test(unittest.TestCase):
    expected = [10, 11, 12, 13, 14, 15]
    def test(self):
        self.assertCountEqual(diving_board(2, 3, 5), self.expected)

if __name__ == '__main__':
    unittest.main()