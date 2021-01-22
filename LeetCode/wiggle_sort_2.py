class Solution(object):
    def wiggleSort(self, nums):
        tmp = sorted(nums)
        l = 0
        h = (len(nums) - 1) // 2 + 1
        for i in range(len(nums) - 1, -1, -1):
            if i % 2:
                nums[i] = tmp[h]
                h += 1
            else:
                nums[i] = tmp[l]
                l += 1
        
        return

if __name__ == "__main__":
    nums = [1, 5, 1, 1, 6, 4, 1]
    sol = Solution()
    sol.wiggleSort(nums)
    print(nums)