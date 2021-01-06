import heapq

class Solution1(object):
    def largestNumber(self, nums):
        num_map = dict()
        digit_set = set()
        for num in nums:
            digit = 1
            tmp = num
            while tmp >= 10:
                digit *= 10
                tmp //= 10
            
            if digit not in num_map:
                num_map[digit] = []
            heapq.heappush(num_map[digit], -num)
            digit_set.add(digit)
        
        cand = []
        for digit in digit_set:
            cand.append([-heapq.heappop(num_map[digit]), digit])

        res = ""
        while len(digit_set) > 0 and res != "0":
            max_num = [0, 1]
            max_i = -1
            i = 0
            for num in cand:
                if (max_num[0] * num[1] * 10 + num[0]) < (num[0] * max_num[1] * 10 + max_num[0]):
                    max_num = num
                    max_i = i
                i += 1
            res += str(max_num[0])
            max_digit = cand[max_i][1]
            if len(num_map[max_digit]) > 0:
                cand[max_i] = [-heapq.heappop(num_map[max_digit]), max_digit]
            else:
                digit_set.remove(max_digit)
                cand[max_i] = [0, 1]
        
        return res

class LargetNum(str):
    def __lt__(self, x):
        return self+x > x+ self

class Solution2(object):
    def largestNumber(self, nums):
        res = "".join(sorted(map(str, nums), key = LargetNum))
        return "0" if res[0] == "0" else res
        
if __name__ == '__main__':
    sol = Solution1()
    nums = [2, 10]
    # nums = [3, 30, 34, 5, 9]
    print(sol.largestNumber(nums))
