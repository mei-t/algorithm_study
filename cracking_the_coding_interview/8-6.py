import unittest
from copy import deepcopy

def troy_tower(n, start, tmp, end):
    if n == 0:
        return
    troy_tower(n - 1, start, end, tmp)
    end.append(start.pop())
    troy_tower(n - 1, tmp, start, end)

class Test(unittest.TestCase):
    def test_simple(self):
        start = [6, 5, 4, 3, 2, 1, 0]
        expected = deepcopy(start)
        tmp, end = [], []
        troy_tower(len(start), start, tmp, end)
        self.assertEqual(end, expected)

if __name__ == '__main__':
    unittest.main()