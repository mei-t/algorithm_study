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

class Test(unittest.TestCase):
    def test_simple(self):
        nums1 = [-1, 0, 1, 3, 5, 7]
        self.assertEqual(magic_index(nums1), 3)
        nums2 = [-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13]
        self.assertEqual(magic_index(nums2), 7)

if __name__ == '__main__':
    unittest.main()