import unittest

def find_first_elem(nums):
    m = 0
    while m < len(nums) and nums[m] <= nums[m + 1]:
        m += 1

    for i in range(m + 1, len(nums)):
        while(nums[m] > nums[i]):
            m -= 1

    return m + 1


def find_last_elem(nums):
    n = len(nums) - 1
    while n >= 0 and nums[n] > nums[n - 1]:
        n -= 1

    for i in range(n - 1, 0, -1):
        while(nums[n] < nums[i]):
            n += 1

    return n - 1


def partly_sort(nums):
    m = find_first_elem(nums)
    n = find_last_elem(nums)
    ans = [m, n]
    return ans


class Test(unittest.TestCase):
    nums = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
    def test(self):
        self.assertEqual(partly_sort(self.nums), [3, 9])


if __name__ == '__main__':
    unittest.main()