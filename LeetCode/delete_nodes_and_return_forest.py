# 18:50
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def delNodes(self, root, to_delete):
        to_delete = set(to_delete)
        res = []
        def traverse(node, is_root):
            if not node:
                return None
            next_root = node.val in to_delete
            if is_root and not next_root:
                res.append(node)
            node.left = traverse(node.left, next_root)
            node.right = traverse(node.right, next_root)
            return None if next_root else node
                
        traverse(root, True)
        return res

class Solution1:
    def delNodes(self, root, to_delete):
        to_delete = set(to_delete)
        res = []
        self.traverse(root, to_delete, True, res)
        return res
    
    def traverse(self, node, to_delete, is_root, res):
        if not node:
            return False
        next_root = False
        parent_leaf = False
        if node.val in to_delete:
            next_root = True
            parent_leaf = True
        elif is_root:
            res.append(node)
        
        left_leaf = self.traverse(node.left, to_delete, next_root, res)
        right_leaf = self.traverse(node.right, to_delete, next_root, res)
        
        if left_leaf:
            node.left = None
        if right_leaf:
            node.right = None
        return parent_leaf