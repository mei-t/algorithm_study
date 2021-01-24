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
    while nums.element_at(i) >= 0 and nums.element_at(i) < target:
        i *= 2
    return i // 2, i

def binary_search(nums, left, right, target):
    if left > right:
        return None
    
    if left == right:
        if nums.element_at(left) == -1:
            return None
        return left
    
    mid = (left + right) // 2
    if nums.element_at(mid) == target:
        return mid
    elif nums.element_at(mid) > target or nums.element_at(mid) == -1:
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