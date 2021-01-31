import sys
from collections import deque

class Solution1(object):
    def maxSlidingWindow(self, nums, k):
        res = []
        for i in range(len(nums) - k + 1):
            max_num = -sys.maxsize - 1
            for j in range(k):
                num = nums[i + j]
                if num > max_num:
                    max_num = num
            res.append(max_num)
        return res

class Solution2(object):
    MINIMUM = -sys.maxsize - 1

    def maxSlidingWindow(self, nums, k):
        res = []
        max_num = self.MINIMUM
        max_index = -1
        for i in range(k - 1, len(nums)):
            if max_num == self.MINIMUM:
                for j in range(k):
                    if nums[i - j] > max_num:
                        max_num = nums[i - j]
                        max_index = i - j
            else:
                if nums[i] > max_num:
                    max_num = nums[i]
                    max_index = i
            
            res.append(max_num)

            if max_index == i - k + 1:
                max_num = self.MINIMUM
                max_index = -1

        return res

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        d = deque()
        res = []
        for i, n in enumerate(nums):
            while d and nums[d[-1]] <= n:
                d.pop()
            
            d.append(i)

            if i - d[0] >= k:
                d.popleft()

            if i + 1 >= k:
                res.append(nums[d[0]])
        return res

if __name__ == '__main__':
    # nums = [1, 3, -1, -3, 5, 3, 6, 7]
    nums = [1, -1]
    sol = Solution()
    res = sol.maxSlidingWindow(nums, 1)
    print(res)