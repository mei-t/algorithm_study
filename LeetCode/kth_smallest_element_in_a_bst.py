import unittest

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class SolutionRec(object):
    def kthSmallest(self, root, k):
        def inorder(node):
            if node:
                return inorder(node.left) + [node.val] + inorder(node.right)
            return []

        return inorder(root)[k - 1]

class SolutionIter(object):  
    def kthSmallest(self, root, k):
        node = root
        stack = []
        while(True):
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            k -= 1
            if k == 0:
                return node.val
            node = node.right


def createTree(nums, index):
    if len(nums) <= index or nums[index] == -1:
        return None

    node = TreeNode(nums[index])
    node.left = createTree(nums, index * 2 + 1)
    node.right = createTree(nums, (index + 1) * 2)
    return node

class Test(unittest.TestCase):
    nums1 = [3, 1, 5, 0, 2, 4, 6]
    nums2 = [4, 2, 5, 1, 3]

    def test1_rec(self):
        root = createTree(self.nums1, 0)
        sol = SolutionRec()
        self.assertEqual(sol.kthSmallest(root, 5), 4)

    def test2_rec(self):
        root = createTree(self.nums2, 0)
        sol = SolutionRec()
        self.assertEqual(sol.kthSmallest(root, 4), 4)
    
    def test1_iter(self):
        root = createTree(self.nums1, 0)
        sol = SolutionIter()
        self.assertEqual(sol.kthSmallest(root, 5), 4)

    def test2_iter(self):
        root = createTree(self.nums2, 0)
        sol = SolutionIter()
        self.assertEqual(sol.kthSmallest(root, 4), 4)

if __name__ == '__main__':
    unittest.main()