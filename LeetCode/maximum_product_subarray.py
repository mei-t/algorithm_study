import unittest

class Solution(object):
    def maxProduct(self, nums):
        r = nums[0]
        cur_max = r
        cur_min = r
        for i in range(1, len(nums)):
            if nums[i] < 0:
                cur_max, cur_min = cur_min, cur_max
            
            cur_max = max(nums[i], nums[i] * cur_max)
            cur_min = min(nums[i], nums[i] * cur_min)

            r = max(r, cur_max)
        
        return r


class Test(unittest.TestCase):
    def test_simple1(self):
        nums = [2,3,-2,4]
        sol = Solution()
        self.assertEqual(sol.maxProduct(nums), 6)

    def test_simple2(self):
        nums = [-2,0,-1]
        sol = Solution()
        self.assertEqual(sol.maxProduct(nums), 0)

    def test_simple3(self):
        nums = [2,-5,-2,-4,3]
        sol = Solution()
        self.assertEqual(sol.maxProduct(nums), 24)

if __name__ == '__main__':
    unittest.main()