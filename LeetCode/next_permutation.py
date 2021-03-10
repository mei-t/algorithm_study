# 48:15
class Solution:
    def nextPermutation(self, nums):
        most_left = len(nums) - 1
        while most_left > 0 and nums[most_left] <= nums[most_left - 1]:
            most_left -= 1
        most_left -= 1
        if most_left < 0:
            nums.sort()
            return
        min_num = float('inf')
        min_index = -1
        for i in range(most_left + 1, len(nums)):
            if nums[i] > nums[most_left] and nums[i] < min_num:
                min_num = nums[i]
                min_index = i
        nums[min_index], nums[most_left] = nums[most_left], nums[min_index]
        self.partial_sort(nums, most_left + 1, len(nums) - 1)
    
    def partial_sort(self, nums, min_index, max_index):
        if min_index >= max_index:
            return
        
        r = nums[max_index]
        bound = min_index
        for i in range(min_index, max_index):
            if nums[i] < r:
                nums[i], nums[bound] = nums[bound], nums[i]
                bound += 1
        nums[bound], nums[max_index] = nums[max_index], nums[bound]
        self.partial_sort(nums, min_index, bound - 1)
        self.partial_sort(nums, bound + 1, max_index)

class Solution2:
    def nextPermutation(self, nums):
        most_left = len(nums) - 1
        while most_left > 0 and nums[most_left] <= nums[most_left - 1]:
            most_left -= 1
        most_left -= 1
        if most_left < 0:
            nums.sort()
            return
        min_num = float('inf')
        min_index = -1
        for i in range(most_left + 1, len(nums)):
            if nums[i] > nums[most_left] and nums[i] <= min_num:
                min_num = nums[i]
                min_index = i
        nums[min_index], nums[most_left] = nums[most_left], nums[min_index]
        left = most_left + 1
        right = len(nums) - 1
        for i in range((right - left + 1) // 2):
            nums[left + i], nums[right - i] = nums[right - i], nums[left + i]