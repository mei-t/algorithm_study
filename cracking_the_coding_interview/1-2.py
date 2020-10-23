import unittest

def isPermutation1(a, b):
    return sorted(a) == sorted(b)

def isPermutation2(a, b):
    if len(a) != len(b):
        return False

    char_map = dict()
    for c in a:
        if c not in char_map:
            char_map[c] = 0
        char_map[c] += 1
    
    for c in b:
        if c not in char_map:
            return False
        if char_map[c] < 1:
            return False
        char_map[c] -= 1
    
    return True

class Test(unittest.TestCase):
    a = "abc"
    b = "bac"
    c = "adc"
    d = "abc "

    def test1_true(self):
        self.assertTrue(isPermutation1(self.a, self.b))
    
    def test1_false_simple(self):
        self.assertFalse(isPermutation1(self.a, self.c))

    def test1_false_with_whitespace(self):
        self.assertFalse(isPermutation1(self.a, self.d))

    def test2_true(self):
        self.assertTrue(isPermutation2(self.a, self.b))

    def test2_false_simple(self):
        self.assertFalse(isPermutation2(self.a, self.c))

    def test2_false_with_whitespace(self):
        self.assertFalse(isPermutation2(self.a, self.d))


if __name__ == '__main__':
    unittest.main()