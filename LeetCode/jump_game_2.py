class Solution:
    def jump(self, nums):
        dp = [0] * len(nums)
        for i in reversed(range(len(nums) - 1)):
            tmp = float('inf')
            for j in range(min(nums[i], len(nums) - i - 1)):
                tmp = min(tmp, dp[i + j + 1] + 1)
            dp[i] = tmp
        return dp[0]