import unittest

class WordFreq:
    wordMap = {}
    
    def __init__(self, s):
        self.s = s
    
    def compute(self, word):
        s_list = self.s.split(" ")
        if word in self.wordMap:
            return self.wordMap[word] / len(s_list)
        count = 0
        i = self.s.find(word)
        while i > -1:
            i = self.s.find(word, i + 1)
            count += 1
        ans = count / len(s_list)
        self.wordMap[word] = count
        return ans

class WordFreq2:
    wordMap = dict()

    def __init__(self, s):
        s = s.replace(".", "")
        s = s.replace(",", "")
        s = s.replace("!", "")
        s = s.replace("?", "")
        s_list = s.split(" ")
        self.sLen = len(s_list)

        for word in s_list:
            if word not in self.wordMap:
                self.wordMap[word] = 0
            self.wordMap[word] += 1
    
    def compute(self, word):
        return self.wordMap[word] / self.sLen

class Test(unittest.TestCase):
    s = "A new door to the unbelievable, to the possible, a new day that can always bring you anything if you have no objection to it."
    wf = WordFreq2(s)

    def test(self):
        self.assertEqual(self.wf.compute("to"), 0.12)
        self.assertEqual(self.wf.compute("door"), 0.04)
        self.assertEqual(self.wf.compute("it"), 0.04)
        self.assertEqual(self.wf.compute("to"), 0.12)

if __name__ == '__main__':
    unittest.main()