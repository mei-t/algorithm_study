class Solution(object):
    def findPeakElement(self, nums):
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return 0
        if nums[0] > nums[1]:
            return 0
        if nums[len(nums) - 1] > nums[len(nums) - 2]:
            return len(nums) - 1

        for i in range(1, len(nums) - 1):
            if nums[i] > nums[i - 1] and nums[i] > nums[i + 1]:
                return i

if __name__ == "__main__":
    nums = [1, 2, 1, 3, 5, 6, 4]
    sol = Solution()
    print(sol.findPeakElement(nums))