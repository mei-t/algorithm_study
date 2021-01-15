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

def find_target2(nums, target):
    return bs_target2(nums, target, 0, len(nums) - 1)

def bs_target2(nums, target, left, right):
    mid = (left + right) // 2
    if nums[mid] == target:
        return mid

    if left >= right:
        return None
    
    if (nums[left] <= target and target < nums[mid]) or\
         (nums[mid] < nums[left] and nums[left] <= target):
         return bs_target2(nums, target, left, mid)
    if nums[left] == nums[mid]:
        if nums[right] == nums[mid]:
            left_res = bs_target2(nums, target, left, mid)
            if left_res:
                return left_res
    return bs_target2(nums, target, mid + 1, right)

class Test(unittest.TestCase):
    def test_simple(self):
        nums = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
        self.assertEqual(find_target2(nums, 5), 8)
        self.assertEqual(find_target2(nums, 19), 2)
    
    def test_with_duplicate(self):
        nums = [2, 2, 2, 3, 4, 2]
        self.assertEqual(find_target2(nums, 4), 4)
        self.assertEqual(find_target2(nums, 3), 3)

if __name__ == '__main__':
    unittest.main()