import unittest

def is_unique(s):
    strSet = set()

    for i in range(len(s)):
        if s[i] in strSet:
            return False

        strSet.add(s[i])

    return True


def is_unique_sorted(s):
    sorted_s = sorted(s)

    for i in range(len(s) - 1):
        if sorted_s[i] == sorted_s[i + 1]:
            return False

    return True


class Test(unittest.TestCase):
    dataTrue = ["abcd", "j39afA", "(o3}2/", " "]
    dataFalse = ["abac", "339afA", "(o/}2/", "  "]

    def test_true(self):
        for s in self.dataTrue:
            self.assertTrue(is_unique(s))

    def test_false(self):
        for s in self.dataFalse:
            self.assertFalse(is_unique(s))

    def test_true_sorted(self):
        for s in self.dataTrue:
            self.assertTrue(is_unique_sorted(s))

    def test_false_sorted(self):
        for s in self.dataFalse:
            self.assertFalse(is_unique_sorted(s))


if __name__ == '__main__':
    unittest.main()