import unittest

class Array:
    def __init__(self, array=[]):
        self.array = sorted(array)
    
    def element_at(self, i):
        if not self.array or len(self.array) <= i:
            return -1
        return self.array[i]
    
    def size(self):
        return len(self.array)

def find_index(nums, x):
    if nums.element_at(0) == -1:
        return None

    if nums.element_at(0) == x:
        return 0
    
    l, r = find_range(nums, x)
    return binary_search(nums, l, r, x)

def find_range(nums, target):
    i = 1
    l = i
    while nums.element_at(i) >= 0 and nums.element_at(i) < target:
        l = i
        i *= 2
    return l, binary_search_range(nums, l, i, target)

def binary_search_range(nums, left, right, target):
    if left > right:
        return right
    mid = (left + right) // 2
    if nums.element_at(mid) >= 0 and nums.element_at(mid + 1) == -1:
        return mid + 1

    if nums.element_at(mid) > target:
        return mid
    
    if nums.element_at(mid) == -1:
        return binary_search_range(nums, left, mid, target)
    else:
        return binary_search_range(nums, mid + 1, right, target)

def binary_search(nums, left, right, target):
    if left > right:
        return None
    
    mid = (left + right) // 2
    if nums.element_at(mid) == target:
        return mid
    elif nums.element_at(mid) > target:
        return binary_search(nums, left, mid, target)
    else:
        return binary_search(nums, mid + 1, right, target)

class Test(unittest.TestCase):
    def test_simple(self):
        nums = [0, 1, 2, 3, 4, 5]
        array = Array(nums)
        for i in range(array.size()):
            self.assertEqual(find_index(array, i), i)
        
        self.assertEqual(find_index(array, array.size()), None)

if __name__ == "__main__":
    unittest.main()