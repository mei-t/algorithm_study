class Solution:
    def threeSumClosest(self, nums, target):
        nums.sort()
        diff = float('inf')
        for i in range(0, len(nums) - 2):
            l = i + 1
            h = len(nums) - 1
            while l < h:
                tmp = nums[i] + nums[l] + nums[h]
                if abs(tmp - target) < abs(diff):
                    diff = tmp - target
                if diff == 0:
                    break
                if tmp < target:
                    l += 1
                else:
                    h -= 1
        
        return diff + target