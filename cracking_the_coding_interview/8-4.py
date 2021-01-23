import copy, unittest

def partial_collection(nums):
    pcs = [[]]
    for num in nums:
        tmp = copy.copy(pcs)
        for pc in tmp:
            new_pc = copy.copy(pc)
            new_pc.append(num)
            pcs.append(new_pc)
        
    return pcs

class Test(unittest.TestCase):
    def test_simple(self):
        nums = [1, 2, 3]
        expected = [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]
        self.assertCountEqual(partial_collection(nums), expected)

if __name__ == "__main__":
    unittest.main()