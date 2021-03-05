import unittest

class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def find_common_parent(root, val1, val2):
    return search(root, val1, val2)[0]

def search(node, val1, val2):
    if not node:
        return None, False
    
    if node.val == val1 or node.val == val2:
        if val1 == val2:
            return node, True
        if search(node.left, val1, val2)[1] or search(node.right, val1, val2)[1]:
            return node, True
        return None, True
    left_node, is_left = search(node.left, val1, val2)
    right_node, is_right = search(node.right, val1, val2)
    if is_left and is_right:
        return node, True
    if left_node:
        return left_node, True
    if right_node:
        return right_node, True
    return None, is_left or is_right

def create_tree(nums, i):
    if len(nums) <= i:
        return None
    node = TreeNode(nums[i])
    node.left = create_tree(nums, i * 2 + 1)
    node.right = create_tree(nums, i * 2 + 2)
    return node

class Test(unittest.TestCase):
    def test_simple(self):
        nums = [0, 1, 2, 3, 4, 5, 6, 7, 8]
        root = create_tree(nums, 0)
        self.assertEqual(find_common_parent(root, 5, 6).val, 2)
        self.assertEqual(find_common_parent(root, 5, 7).val, 0)
        self.assertEqual(find_common_parent(root, 4, 7).val, 1)

if __name__ == '__main__':
    unittest.main()