class Solution(object):
    def search(self, nums, target):
        return self.binary_search(nums, target, 0, len(nums) - 1)
    
    def binary_search(self, nums, target, left, right):
        mid = (left + right) // 2
        print(left, mid, right)
        if nums[mid] == target:
            return mid

        if left >= right:
            return -1
        
        if nums[left] <= nums[mid]:
            if nums[left] <= target and target <= nums[mid]:
                return self.binary_search(nums, target, left, mid)
            else:
                return self.binary_search(nums, target, mid + 1, right)
        else:
            if nums[mid] <= target and target <= nums[right]:
                return self.binary_search(nums, target, mid + 1, right)
            else:
                return self.binary_search(nums, target, left, mid)


if __name__ == '__main__':
    # nums = [4, 5, 6, 7, 0, 1, 2]
    nums = [3, 1]
    sol = Solution()
    res = sol.search(nums, 1)
    print(res)