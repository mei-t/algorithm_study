import unittest

def can_convert_at_once(s1, s2):
    if len(s1) == len(s2):
        return can_convert_by_replace(s1, s2)
    
    if len(s1) > len(s2):
        return can_convert_by_insert(s2, s1)
    
    return can_convert_by_insert(s1, s2)

def can_convert_by_replace(s1, s2):
    count = 0
    for i in range(len(s1)):
        if s1[i] == s2[i]:
            continue
        count += 1
        if count > 1:
            return False
    
    return True

def can_convert_by_insert(shorter, longer):
    pos_diff = 0
    for i in range(len(shorter)):
        if shorter[i] == longer[i + pos_diff]:
            continue
        pos_diff += 1
        if pos_diff > 1:
            return False
    
    return True

class Test(unittest.TestCase):
    data_T = [
        ["pale", "ple"],
        ["pales", "pale"],
        ["pale", "bale"]
    ]
    data_F = [["pale", "bake"]]

    def test_true(self):
        for d in self.data_T:
            self.assertTrue(can_convert_at_once(d[0], d[1]))
    
    def test_false(self):
        for d in self.data_F:
            self.assertFalse(can_convert_at_once(d[0], d[1]))

if __name__ == '__main__':
    unittest.main()