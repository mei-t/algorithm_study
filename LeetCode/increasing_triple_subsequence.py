import unittest

class Solution(object):
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
    input = [1, 2, 3, 4, 5]
    def test(self):
        sol = Solution()
        self.assertTrue(sol.increasingTriplet(self.input))


if __name__ == '__main__':
    unittest.main()