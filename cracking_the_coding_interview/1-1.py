import unittest

def is_unique(s):
    strSet = set()

    for c in s:
        if c in strSet:
            return False

        strSet.add(c)

    return True


# inputの文字コードはASCII
def is_unique2(s):
    chars = [0] * 128
    for c in s:
        if chars[ord(c)] > 0:
            return False

        chars[ord(c)] += 1
    
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

    def test_true2(self):
        for s in self.dataTrue:
            self.assertTrue(is_unique2(s))

    def test_false2(self):
        for s in self.dataFalse:
            self.assertFalse(is_unique2(s))

    def test_true_sorted(self):
        for s in self.dataTrue:
            self.assertTrue(is_unique_sorted(s))

    def test_false_sorted(self):
        for s in self.dataFalse:
            self.assertFalse(is_unique_sorted(s))


if __name__ == '__main__':
    unittest.main()