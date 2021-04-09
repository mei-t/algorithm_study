# 13:15
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flipEquiv(self, root1, root2):
        return self.checkEquiv(root1, root2)
    
    def checkEquiv(self, node1, node2):
        if not node1 and not node2:
            return True
        if not node1 or not node2:
            return False
        if node1.val != node2.val:
            return False
        
        if self.checkEquiv(node1.left, node2.left) and self.checkEquiv(node1.right, node2.right):
            return True
        return self.checkEquiv(node1.left, node2.right) and self.checkEquiv(node1.right, node2.left)