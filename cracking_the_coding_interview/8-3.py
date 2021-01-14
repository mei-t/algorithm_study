import unittest

def magic_index(nums):
    return bs_magic_index(nums, 0, len(nums))

def bs_magic_index(nums, l, r):
    if l == r:
        return l if nums[l] == l else NotImplemented
    
    mid = (l + r) // 2
    if nums[mid] < mid:
        return bs_magic_index(nums, mid + 1, r)
    elif nums[mid] > mid:
        return bs_magic_index(nums, l, mid)
    else:
        return mid

def magic_index2(nums):
    return find_magic_index(nums, 0, len(nums))

def find_magic_index(nums, left, right):
    if left > right:
        return None
    
    mid = (left + right) // 2
    if nums[mid] == mid:
        return mid
    
    new_right = min(mid - 1, nums[mid])
    left_res = find_magic_index(nums, left, new_right)
    if left_res:
        return left_res
    
    new_left = max(mid + 1, nums[mid])
    return find_magic_index(nums, new_left, right)

class Test(unittest.TestCase):
    def test_magic_index(self):
        nums1 = [-1, 0, 1, 3, 5, 7]
        self.assertEqual(magic_index(nums1), 3)
        nums2 = [-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13]
        self.assertEqual(magic_index(nums2), 7)
    
    def test_magic_index2(self):
        nums1 = [-10, -5, 2, 2, 2, 3, 4, 6, 9, 12, 13]
        self.assertEqual(magic_index2(nums1), 2)

if __name__ == '__main__':
    nums1 = [-10, -5, 2, 2, 2, 3, 4, 6, 9, 12, 13]
    # print(magic_index2(nums1))
    unittest.main()