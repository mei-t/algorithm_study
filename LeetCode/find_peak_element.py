class Solution1(object):
    def findPeakElement(self, nums):
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                return i
        return len(nums) - 1

class Solution2(object):
    def findPeakElement(self, nums):
        return self.binarySearch(0, len(nums) - 1, nums)
    
    def binarySearch(self, l, r, nums):
        if l == r:
            return l

        mid = (l + r) // 2
        if nums[mid] > nums[mid + 1]:
            return self.binarySearch(l, mid, nums)
        return self.binarySearch(mid + 1, r, nums)

if __name__ == "__main__":
    nums = [1, 2, 1, 3, 5, 6, 4]
    sol = Solution2()
    print(sol.findPeakElement(nums))