import unittest

class Solution(object):
    max_num = 2147483647
    min_num = -2147483648

    def myAtoi(self, s):
        stage = 0
        is_negative = False
        ans = 0
        for c in s:
            if ord('0') <= ord(c) and ord(c) <= ord('9'):
                ans *= 10
                ans += int(c)
                stage = 2
                if ans >= self.max_num:
                    break
            
            elif stage > 0:
                break

            elif c == '+' or c == '-':
                stage = 1
                if c == '-':
                    is_negative = True

            elif c != ' ':
                break
        
        if is_negative:
            ans *= -1
        
        if ans > self.max_num:
            return self.max_num
        if ans < self.min_num:
            return self.min_num
        
        return ans

class Test(unittest.TestCase):
    def test_simple(self):
        sol = Solution()
        res = sol.myAtoi("42")
        self.assertEqual(res, 42)
    
    def test_with_white_space(self):
        sol = Solution()
        res = sol.myAtoi("   -42")
        self.assertEqual(res, -42)
    
    def test_with_post_words(self):
        sol = Solution()
        res = sol.myAtoi("4193 with word")
        self.assertEqual(res, 4193)
    
    def test_with_pre_words(self):
        sol = Solution()
        res = sol.myAtoi("words and 987")
        self.assertEqual(res, 0)
    
    def test_overflow(self):
        sol = Solution()
        res = sol.myAtoi("-91283472332")
        self.assertEqual(res, -2147483648)

if __name__ == '__main__':
    unittest.main()