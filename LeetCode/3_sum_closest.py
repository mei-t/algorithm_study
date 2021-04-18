# O(n^2)
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

# O((n^2)logn)
class Solution2:
    def threeSumClosest(self, nums, target):
        nums.sort()
        diff = float('inf')
        for i in range(0, len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                l = j + 1
                r = len(nums)
                while l < r:
                    mid = (l + r) // 2
                    tmp = nums[i] + nums[j] + nums[mid]
                    if abs(tmp - target) < abs(diff):
                        diff = tmp - target
                    if tmp - target == 0:
                        break
                    if tmp - target < 0:
                        l = mid + 1
                    else:
                        r = mid
        
        return diff + target