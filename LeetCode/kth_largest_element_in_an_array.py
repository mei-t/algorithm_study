class Solution(object):
    def findKthLargest(self, nums, k):
        nums.sort(reverse=True)
        print(nums)
        return nums[k - 1]

if __name__ == '__main__':
    nums = [3,2,1,5,6,4]
    sol = Solution()
    print(sol.findKthLargest(nums, 2))