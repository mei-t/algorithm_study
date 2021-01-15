import unittest

def find_target(nums, target):
    return bs_target(nums, target, 0, len(nums))

def bs_target(nums, target, left, right):
    mid = (left + right) // 2
    if nums[mid] == target:
        return mid
    if (nums[left] < target and target < nums[mid]) or\
         (nums[mid] < nums[left] and nums[left] < target):
         return bs_target(nums, target, left, mid)
    return bs_target(nums, target, mid + 1, right)

class Test(unittest.TestCase):
    def test_simple(self):
        nums = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
        self.assertEqual(find_target(nums, 5), 8)
        self.assertEqual(find_target(nums, 19), 2)

if __name__ == '__main__':
    unittest.main()