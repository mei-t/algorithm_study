import copy

class Solution(object):
    def subsets(self, nums):
        res = [[]]
        self.addSubsets(nums, 0, res)
        return res

    def addSubsets(self, nums, i, res):
        if i >= len(nums):
            return

        for j in range(len(res)):
            newSubset = copy.deepcopy(res[j])
            newSubset.append(nums[i])
            res.append(newSubset)

        self.addSubsets(nums, i+1, res)

if __name__ == '__main__':
    nums = [1,2,3]
    sol = Solution()
    res = sol.subsets(nums)
    print(res)