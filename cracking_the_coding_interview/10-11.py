def mountain_vally(nums):
    nums.sort()
    mid = len(nums) // 2
    first_idx = 0
    second_idx = mid
    res = []
    while second_idx < len(nums):
        res.append(nums[second_idx])
        second_idx += 1
        if first_idx < mid:
            res.append(nums[first_idx])
            first_idx += 1
    return res

if __name__ == '__main__':
    nums = [5, 3, 1, 2, 3]
    res = mountain_vally(nums)
    print(res)