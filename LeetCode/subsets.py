import copy

class Solution(object):
    def subsets(self, nums):
        res = [[]]
        
        for num in nums:
            res += [cur + [num] for cur in res]
        
        return res

if __name__ == '__main__':
    nums = [1,2,3]
    sol = Solution()
    res = sol.subsets(nums)
    print(res)