import unittest

def is_palindrome(s):
    char_map = dict()
    for c in s.lower().replace(" ", ""):
        if c not in char_map:
            char_map[c] = 0
        char_map[c] += 1
    
    odd_count = 0
    for c in char_map:
        if char_map[c] % 2:
            odd_count += 1
            if odd_count > 1:
                return False
    return True

def is_palindrome_with_bit_vector(s):
    bit_vector = 0
    for c in s.lower().replace(" ", ""):
        x = 1 << (ord(c) - ord("a"))
        bit_vector ^= x

    if bit_vector == 0:
        return True

    odd_appear = False
    for i in range(26):
        x = 1 << i
        if bit_vector & x:
            if odd_appear:
                return False
            odd_appear = True

    return True

class Test(unittest.TestCase):
    t_data = ["Tact Coa", "a", "", "ksjesssjeek"]
    f_data = ["Tact Co", "ab", "sjfueska"]

    def test_true(self):
        for data in self.t_data:
            self.assertTrue(is_palindrome_with_bit_vector(data))
    
    def test_false(self):
        for data in self.f_data:
            self.assertFalse(is_palindrome_with_bit_vector(data))

if __name__ == '__main__':
    unittest.main()
