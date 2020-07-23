class Solution(object):
    def searchRange(self, nums, target):
        first = self.findFirst(nums, target, 0, len(nums) - 1)
        if first == -1:
            return [-1, -1]
        
        last = self.findLast(nums, target, first, len(nums) - 1)
        return [first, last]

    def findFirst(self, nums, target, left, right):
        if left > right:
            return -1
        
        mid = (left + right) // 2
        if nums[mid] == target:
            if mid == 0 or nums[mid - 1] < target:
                return mid
            return self.findFirst(nums, target, left, mid)

        if nums[mid] > target:
            return self.findFirst(nums, target, left, mid - 1)

        return self.findFirst(nums, target, mid + 1, right)


    def findLast(self, nums, target, left, right):
        if left > right:
            return -1
        
        mid = (left + right) // 2
        if nums[mid] == target:
            if mid + 1 == len(nums) or nums[mid + 1] > target:
                return mid
            return self.findLast(nums, target, mid + 1, right)

        if nums[mid] > target:
            return self.findLast(nums, target, left, mid - 1)

        return self.findLast(nums, target, mid + 1, right)

if __name__ == '__main__':
    nums = [5,7,7,8,8,10]
    sol = Solution()
    print(sol.searchRange(nums, 8))
    print(sol.searchRange(nums, 6))