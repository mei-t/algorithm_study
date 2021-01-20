class Solution(object):
    def threeSum(self, nums):
        if len(nums) < 3:
            return []
        
        pos, neg = [], []
        count_zero = 0
        for num in nums:
            if num == 0:
                count_zero += 1
            elif num > 0:
                pos.append(num)
            else:
                neg.append(num)
        
        pos.sort()
        neg.sort()

        res = []
        if count_zero > 2:
            res.append([0, 0, 0])
        
        if count_zero > 0:
            self.twoSum(res, pos, neg)
        
        self.threeSumHalf(res, pos, neg)
        self.threeSumHalf(res, neg, pos)
        return res
    
    def twoSum(self, res, pos, neg):
        num_set = set()
        for num in pos:
            num_set.add(-num)
        
        for num in neg:
            if num in num_set:
                res.append([num, 0, -num])
                num_set.remove(num)
    
    def threeSumHalf(self, res, two_pick, one_pick):
        num_map = dict()
        num_set = set()
        for i in range(1, len(two_pick)):
            for j in range(0, i):
                key_str = str(two_pick[i]) + " " + str(two_pick[j])
                if key_str in num_set:
                    continue
                key = -two_pick[i] - two_pick[j]
                if key not in num_map:
                    num_map[key] = []
                num_map[key].append([two_pick[i], two_pick[j]])
                num_set.add(key_str)
        
        for num in one_pick:
            if num in num_map:
                for nums in num_map[num]:
                    nums.append(num)
                    res.append(nums)
                num_map.pop(num)

if __name__ == "__main__":
    nums = [-1, 0, 1, 2, -1, -4]
    sol = Solution()
    res = sol.threeSum(nums)
    print(res)