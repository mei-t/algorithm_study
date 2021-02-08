import unittest

class TreeNode(object):
    def __init__(self, val=0, parent=None, left=None, right=None):
        self.val = val
        self.parent = parent
        self.left = left
        self.right = right

def find_next_node(node):
    if node.right:
        node = node.right
        while node.left:
            node = node.left
        return node
    
    while node.parent and node.parent.left != node:
        node = node.parent
    
    return node.parent

class Test(unittest.TestCase):
    def test_simple(self):
        node1 = TreeNode(6)
        node2 = TreeNode(3, node1)
        node3 = TreeNode(10, node1)
        node4 = TreeNode(2, node2)
        node5 = TreeNode(5, node2)
        node6 = TreeNode(9, node3)
        node7 = TreeNode(12, node3)
        node1.left = node2
        node1.right = node3
        node2.left = node4
        node2.right = node5
        node3.left = node6
        node3.right = node7

        self.assertEqual(find_next_node(node1), node6)
        self.assertEqual(find_next_node(node2), node5)
        self.assertEqual(find_next_node(node3), node7)
        self.assertEqual(find_next_node(node4), node2)
        self.assertEqual(find_next_node(node5), node1)
        self.assertEqual(find_next_node(node6), node3)
        self.assertEqual(find_next_node(node7), None)

if __name__ == '__main__':
    unittest.main()