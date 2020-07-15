import unittest

class WordFreq:
    wordMap = {}
    
    def __init__(self, s):
        self.s = s
    
    def compute(self, word):
        if word in self.wordMap:
            return self.wordMap[word]
        count = 0
        i = self.s.find(word)
        while i > -1:
            i = self.s.find(word, i + 1)
            count += 1
        s_list = self.s.split(" ")
        ans = count / len(s_list)
        self.wordMap[word] = count
        return ans

class Test(unittest.TestCase):
    s = "A new door to the unbelievable, to the possible, a new day that can always bring you anything if you have no objection to it."
    wf = WordFreq(s)

    def test(self):
        self.assertEqual(self.wf.compute("to"), 0.12)
        self.assertEqual(self.wf.compute("door"), 0.04)

if __name__ == '__main__':
    unittest.main()