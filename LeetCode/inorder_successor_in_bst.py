class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def inorderSuccessor(self, root, p):
        return self.inorderSearch(root, p)
    
    def inorderSearch(self, node, p):
        if not node:
            return
        
        res = None
        if node.val == p.val:
            if node.right:
                return self.findNext(node.right)
        elif node.val > p.val:
            res = self.inorderSearch(node.left, p)
            if not res:
                return node
        else:
            res = self.inorderSearch(node.right, p)
        
        return res
    
    def findNext(self, node):
        if not node.left:
            return node
        return self.findNext(node.left)

