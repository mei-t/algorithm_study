import unittest

def find_index(words, target):
    return search(words, target, 0, len(words))

def search(words, target, left, right):
    if left >= right:
        return -1
    
    mid = (left + right) // 2
    
    start_m = mid
    while mid < right - 1 and words[mid] == "":
        mid += 1

    if words[mid] == target:
        return mid
    
    if words[mid] == "":
        return search(words, target, left, start_m)
    elif words[mid] > target:
        return search(words, target, left, start_m)
    
    return search(words, target, mid + 1, right)

class Test(unittest.TestCase):
    def test_simple(self):
        words = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]
        self.assertEqual(find_index(words, "at"), 0)
        self.assertEqual(find_index(words, "ball"), 4)
        self.assertEqual(find_index(words, "car"), 7)
        self.assertEqual(find_index(words, "dad"), 10)
        self.assertEqual(find_index(words, "bake"), -1)

if __name__ == '__main__':
    unittest.main()