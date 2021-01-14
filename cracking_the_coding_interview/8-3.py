import unittest

def magic_index(nums):
    return bts_magic_index(nums, 0, len(nums))

def bts_magic_index(nums, l, r):
    if l == r:
        return l if nums[l] == l else NotImplemented
    
    mid = (l + r) // 2
    if nums[mid] < mid:
        return bts_magic_index(nums, mid + 1, r)
    elif nums[mid] > mid:
        return bts_magic_index(nums, l, mid)
    else:
        return mid

class Test(unittest.TestCase):
    def test_simple(self):
        nums = [-1, 0, 1, 3, 5, 7]
        self.assertEqual(magic_index(nums), 3)

if __name__ == '__main__':
    unittest.main()