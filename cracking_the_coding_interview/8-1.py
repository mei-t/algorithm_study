import unittest

def count_ways(k, map):
    if k in map:
        return map[k]
    if k < 0:
        return 0
    if k == 0:
        return 1
    map[k] = triple_step(k - 1) + triple_step(k - 2) + triple_step(k - 3)
    return map[k]

def triple_step(k):
    return count_ways(k, dict())

class Test(unittest.TestCase):
    def test_simple(self):
        self.assertEqual(triple_step(3), 4)
        self.assertEqual(triple_step(6), 24)

if __name__ == '__main__':
    unittest.main()