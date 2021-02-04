import unittest

def compress_string(s):
    prev = s[0]
    count = 1
    compressed = ""
    for i in range(1, len(s)):
        if s[i] != prev:
            compressed += prev + str(count)
            count = 0
        prev = s[i]
        count += 1
    compressed += prev + str(count)
    return compressed if len(compressed) < len(s) else s

class Test(unittest.TestCase):
    data_compressed = [["aabcccccaaa", "a2b1c5a3"], ["aaa", "a3"]]
    data_not_compressed = [["a", "a"], ["aa", "aa"], ["abcdef", "abcdef"]]

    def test_compressed(self):
        for d in self.data_compressed:
            self.assertEqual(compress_string(d[0]), d[1])

    def test_not_compressed(self):
        for d in self.data_not_compressed:
            self.assertEqual(compress_string(d[0]), d[1])

if __name__ == '__main__':
    unittest.main()
