import unittest

def urlify(s, l):
    return s.replace(" ", "%20")

def urlify_without_method(s, l):
    blannk_count = 0
    for i in range(l):
        if s[i] == " ":
            blannk_count += 1
        
    new_str = [" " for _ in range(blannk_count * 2 + l)]
    new_str_i = blannk_count * 2 + l - 1 
    for i in reversed(range(l)):
        if s[i] == " ":
            new_str[new_str_i - 2: new_str_i + 1] = "%20"
            new_str_i -= 3
        else:
            new_str[new_str_i] = s[i]
            new_str_i -= 1

    return "".join([c for c in new_str]) 

class Test(unittest.TestCase):
    data = [(("Mr John Smith   ", 13), "Mr%20John%20Smith"), ((" a b c", 6), "%20a%20b%20c")]

    def test(self):
        for d in self.data:
            self.assertEqual(d[1], urlify_without_method(d[0][0], d[0][1]))

if __name__ == "__main__":
    unittest.main()