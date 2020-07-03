import unittest

def partly_sort(nums):
    m = 0
    n = len(nums) - 1

    while m < len(nums) and nums[m] <= nums[m + 1]:
        m += 1

    while n >= 0 and nums[n] > nums[n - 1]:
        n -= 1
    
    max_i = m
    min_i = n
    for i in range(m + 1, n):
        if nums[max_i] < nums[i]:
            max_i = i
        if nums[min_i] > nums[i]:
            min_i = i

    while nums[m] > nums[min_i]:
        m -= 1

    while nums[n] < nums[max_i]:
        n += 1

    ans = [m + 1, n - 1]
    return ans


class Test(unittest.TestCase):
    nums = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
    def test(self):
        self.assertEqual(partly_sort(self.nums), [3, 9])


if __name__ == '__main__':
    unittest.main()