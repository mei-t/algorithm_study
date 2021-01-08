class Solution(object):
    char_map = {
        "2": ["a", "b", "c"],
        "3": ["d", "e", "f"],
        "4": ["g", "h", "i"],
        "5": ["j", "k", "l"],
        "6": ["m", "n", "o"],
        "7": ["p", "q", "r", "s"],
        "8": ["t", "u", "v"],
        "9": ["w", "x", "y", "z"]
    }

    def letterCombinations(self, digits):
        if len(digits) == 0:
            return []
        res = []
        self.nextLetter(digits, 0, "", res)
        return res
    
    def nextLetter(self, digits, i, s, res):
        if i >= len(digits):
            res.append(s)
            return
        
        for c in self.char_map[digits[i]]:
            self.nextLetter(digits, i+1, s+c, res)

if __name__ == '__main__':
    sol = Solution()
    digits = "23"
    res = sol.letterCombinations(digits)
    print(res)