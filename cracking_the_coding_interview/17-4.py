INT_SIZE = 32

class BitList(list):
    def __init__(self, nums):
        self.extend(nums)
    
    def get_bit(self, i, j):
        mask = 1 << j
        return self[i] & mask

def find_lost_num(nums, bit):
    if not nums or bit >= INT_SIZE:
        return 0

    zero_bit = BitList([])
    one_bit = BitList([])
    for i in range(len(nums)):
        if nums.get_bit(i, bit):
            one_bit.append(nums[i])
        else:
            zero_bit.append(nums[i])

    if len(zero_bit) > len(one_bit):
        res =  find_lost_num(one_bit, bit + 1)
        return (res << 1) | 1
    res = find_lost_num(zero_bit, bit + 1)
    return res << 1


if __name__ == '__main__':
    n = [3, 5, 2, 0, 7, 8, 10, 1, 4, 9]
    nums = BitList(n)
    res = find_lost_num(nums, 0)
    print(res)