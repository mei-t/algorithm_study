import unittest
import copy

class Solution(object):
    def generateParenthesis(self, n):
        return self.__generate(n, n, [], "")
        
    def __generate(self, p_open, p_close, res, parentheses):
        if p_open == 0 and p_close == 0:
            res.append(parentheses)
            return

        if p_open > 0:
            self.__generate(p_open - 1, p_close, res, parentheses + '(')
            
        if p_close > p_open:
            self.__generate(p_open, p_close - 1, res, parentheses + ')')
            
        return res

class Test(unittest.TestCase):
    output = [
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
    ]

    def test(self):
        sol = Solution()
        self.assertEqual(sol.generateParenthesis(3), self.output)

if __name__ == '__main__':
    unittest.main()