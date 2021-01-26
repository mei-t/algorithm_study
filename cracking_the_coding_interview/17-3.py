import random

def random_subset(nums, m):
    n = len(nums)
    res = []
    for i in range(m):
        res.append(nums[i])
    
    for i in range(m, n):
        r = random.randrange(i)
        if r < m:
            res[r] = nums[i]
    
    return res

if __name__ == "__main__":
    nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    res = random_subset(nums, 3)
    print(res)