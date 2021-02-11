def find_dupli(nums):
    is_find = 0
    for n in nums:
        mask = 1 << n
        if is_find & mask:
            return n
        is_find |= mask
    return None

if __name__ == '__main__':
    nums = [5, 2, 0, 3, 1, 5, 7, 6, 4]
    res = find_dupli(nums)
    print(res)
