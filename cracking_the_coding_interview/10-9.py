def search_sorted_array(nums, target):
    if not nums:
        return None, None
    i = 0
    while True:
        if target < nums[i][0]:
            break
        left = 0
        right = len(nums[0])
        while True:
            if left >= right:
                break
            mid = (left + right) // 2
            if nums[i][mid] == target:
                return i, mid
            if nums[i][mid] > target:
                right = mid
            else:
                left = mid + 1
        i += 1
    
    return None, None

if __name__ == '__main__':
    nums = [
        [0, 3, 7, 9],
        [1, 5, 10, 11],
        [6, 8, 15, 30]
    ]
    i, j = search_sorted_array(nums, 6)
    print(i, j, nums[i][j])
