import unittest

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def kthSmallest(self, root, k):
        return self.find(root, k, 0)[0]

    def find(self, node, k, i):
        if node == None:
            return [i]

        left = self.find(node.left, k, i)
        
        if left[0] >= k:
            return left
        
        if left[0] + 1 == k:
            return[k, node.val]
        
        right = self.find(node.right, k, left[0] + 1)
        return right


def createTree(nums, index):
    if len(nums) <= index or nums[index] == -1:
        return None

    node = TreeNode(nums[index])
    node.left = createTree(nums, index * 2 + 1)
    node.right = createTree(nums, (index + 1) * 2)
    return node

class Test(unittest.TestCase):
    nums1 = [0, 1, 2, 3, 4, 5, 6]
    nums2 = [4, 2, 5, 1, 3]

    def test1(self):
        root = createTree(self.nums1, 0)
        sol = Solution()
        self.assertEqual(sol.kthSmallest(root, 5), 5)

    def test2(self):
        root = createTree(self.nums2, 0)
        sol = Solution()
        self.assertEqual(sol.kthSmallest(root, 4), 4)

if __name__ == '__main__':
    unittest.main()