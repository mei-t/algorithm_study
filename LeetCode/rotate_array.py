class Solution1(object):
    def rotate(self, nums, k):
        while k > 0:
            tmp = nums[-1]
            for i in reversed(range(1, len(nums))):
                nums[i] = nums[i - 1]
            
            nums[0] = tmp
            k -= 1
        
class Solution2(object):
    def rotate(self, nums, k):
        if k == 0:
            return
        count = self.gcd(len(nums), k)
        for i in range(count):
            start_i = i
            nex = nums[start_i]
            tmp = nums[start_i]
            cur_i = (i + k) % len(nums)
            while cur_i != start_i:
                nex = nums[cur_i]
                nums[cur_i] = tmp
                tmp = nex
                cur_i = (cur_i + k) % len(nums)
            nums[cur_i] = tmp
    
    def gcd(self, a, b):
        if a % b == 0:
            return b
        return self.gcd(b, a % b)


if __name__ == '__main__':
    sol = Solution2()
    nums = [1, 2, 3, 4, 5, 6, 7]
    sol.rotate(nums, 3)
    print(nums)