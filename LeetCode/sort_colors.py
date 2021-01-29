from enum import Enum

class Solution1(object):
    def sortColors(self, nums):
        count = [0 for _ in range(3)]

        for num in nums:
            count[num] += 1
        
        index = 0
        for num in range(3):
            for _ in range(count[num]):
                nums[index] = num
                index += 1
        
        return

class Colors(Enum):
    RED = 0
    WHITE = 1
    BLUE = 2

class Solution(object):
    def sortColors(self, nums):
        red_index = -1
        blue_index = len(nums)
        for num in nums:
            if num == 0:
                red_index += 1
            elif num == 2:
                blue_index -= 1
        
        for i in range(len(nums)):
            if i <= red_index:
                nums[i] = 0
            elif i < blue_index:
                nums[i] = 1
            else:
                nums[i] = 2

if __name__ == '__main__':
    nums = [2, 0, 2, 1, 1, 0]
    sol = Solution()
    sol.sortColors(nums)
    print(nums)
