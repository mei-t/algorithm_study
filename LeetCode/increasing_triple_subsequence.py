import unittest
import sys

class Solution(object):
    def increasingTriplet(self, nums):
        first = second = sys.maxsize
        for num in nums:
            if first >= num:
                first = num
            elif second >= num:
                second = num
            else:
                return True
        return False


class SolutionBF(object):
    def increasingTriplet(self, nums):
        prevs = []
        for num in nums:
            for pair in prevs:
                if len(prevs) > 0 and num > pair[0]:
                    if pair[1] > 1:
                        return True
                    prevs.append([num, pair[1] + 1])
            prevs.append([num, 1])
        return False


class Test(unittest.TestCase):
    dataT = [1, 2, 3, 4, 5]
    dataF = [1, 1, 1, 1, 1]

    def test_true(self):
        sol = Solution()
        self.assertTrue(sol.increasingTriplet(self.dataT))

    def test_false(self):
        sol = Solution()
        self.assertFalse(sol.increasingTriplet(self.dataF))
    
    def test_true_bf(self):
        sol = SolutionBF()
        self.assertTrue(sol.increasingTriplet(self.dataT))

    def test_false_bf(self):
        sol = SolutionBF()
        self.assertFalse(sol.increasingTriplet(self.dataF))


if __name__ == '__main__':
    unittest.main()