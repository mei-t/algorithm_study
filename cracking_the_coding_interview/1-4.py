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

class Test(unittest.TestCase):
    t_data = ["Tact Coa", "a", "", "ksjesssjeek"]
    f_data = ["Tact Co", "ab", "sjfueska"]

    def test_true(self):
        for data in self.t_data:
            self.assertTrue(is_palindrome(data))
    
    def test_false(self):
        for data in self.f_data:
            self.assertFalse(is_palindrome(data))

if __name__ == '__main__':
    unittest.main()
