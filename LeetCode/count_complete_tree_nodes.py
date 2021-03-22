
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution(object):
    def countNodes(self, root):
        if not root:
            return 0
        if not root.left:
            return 1
        
        depth = 1
        node = root
        while node.left:
            node = node.left
            depth += 1
        return self.binary_search(root, depth, 1, 0) + 2 ** (depth - 1) - 1
    
    def binary_search(self, node, depth, cur_depth, left_count):
        if not node.right:
            if cur_depth == depth or node.left:
                return left_count + 1
            return left_count + 0
        
        mid_node = node.left
        mid_depth = cur_depth + 1
        while mid_node and mid_node.right:
            mid_node = mid_node.right
            mid_depth += 1
        
        if depth == mid_depth:
            diff = depth - cur_depth
            return self.binary_search(node.right, depth, cur_depth + 1, left_count + 2 ** (diff - 1))
        return self.binary_search(node.left, depth, cur_depth + 1, left_count)