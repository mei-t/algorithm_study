import unittest

class TreeNode:
    def __init__(self, val, count=0, left=None, right=None):
        self.val = val
        self.count = count
        self.left = left
        self.right = right

class RankOfNumber:
    def __init__(self):
        self.root = None
    
    def trace(self, x):
        self.root = self.__trace(x, self.root, 0)
    
    def get_rank_of_number(self, x):
        return self.__get_rank_of_number(x, self.root)
    
    def __trace(self, x, node, count):
        if not node:
            node = TreeNode(x, count)
            return node
        
        if x == node.val:
            node.count += 1
        elif x < node.val:
            node.count += 1
            node.left = self.__trace(x, node.left, count)
        elif x > node.val:
            node.right = self.__trace(x, node.right, count + 1)
        return node
    
    def __get_rank_of_number(self, x, node):
        if not node:
            return 0
        if node.val == x:
            return node.count
        if node.val > x:
            return self.__get_rank_of_number(x, node.left)
        if node.val < x:
            return self.__get_rank_of_number(x, node.right) + node.count

class Test(unittest.TestCase):
    def test_simple(self):
        ron = RankOfNumber()
        ron.trace(5)
        ron.trace(1)
        ron.trace(4)
        ron.trace(4)
        ron.trace(5)
        ron.trace(9)
        ron.trace(7)
        ron.trace(13)
        ron.trace(3)
        self.assertEqual(ron.get_rank_of_number(1), 0)
        self.assertEqual(ron.get_rank_of_number(3), 1)
        self.assertEqual(ron.get_rank_of_number(4), 3)

if __name__ == '__main__':
    unittest.main()
