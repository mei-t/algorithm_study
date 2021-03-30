def mountain_vally2(nums):
    nums.append(float('inf'))
    for i in range(1, len(nums) - 1, 2):
        if nums[i - 1] < nums[i] or nums[i] > nums[i + 1]:
            min_num = min(nums[i - 1], nums[i + 1])
            if min_num == nums[i - 1]:
                nums[i - 1], nums[i] = nums[i], nums[i - 1]
            else:
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
    nums.pop()
    return nums


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
    nums = [9, 1, 0, 4, 8, 7]
    # nums = [5, 3, 1, 2, 3]
    res = mountain_vally2(nums)
    print(res)