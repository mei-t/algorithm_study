INT_SIZE = 32

class BitList(object):
    def __init__(self, nums):
        self.nums = nums
    
    def get_bit(self, i, j):
        mask = 1 << j
        return self.nums[i] & mask
    
    def is_empty(self):
        return len(self.nums) == 0
    
    def check(self):
        return self.nums
    
    def append(self, num):
        self.nums.append(num)
    
    def size(self):
        return len(self.nums)
    
    def get(self, i):
        return self.nums[i]

def find_lost_num(nums, bit):
    if nums.is_empty() or bit >= INT_SIZE:
        return 0

    zero_bit = BitList([])
    one_bit = BitList([])
    for i in range(nums.size()):
        if nums.get_bit(i, bit):
            one_bit.append(nums.get(i))
        else:
            zero_bit.append(nums.get(i))
    
    if zero_bit.size() > one_bit.size():
        res =  find_lost_num(one_bit, bit + 1)
        return (res << 1) | 1
    res = find_lost_num(zero_bit, bit + 1)
    return res << 1


if __name__ == '__main__':
    n = [3, 5, 2, 0, 7, 8, 10, 1, 4, 9]
    nums = BitList(n)
    res = find_lost_num(nums, 0)
    print(res)