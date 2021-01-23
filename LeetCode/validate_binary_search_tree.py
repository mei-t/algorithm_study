class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def isValidBST(self, root):
        return self.isValid(root, -float('inf'), float('inf'))
    
    def isValid(self, node, min_val, max_val):
        if not node:
            return True
        
        if node.val <= min_val or node.val >= max_val:
            return False
        
        is_left_valid = self.isValid(node.left, min_val, node.val)
        if not is_left_valid:
            return is_left_valid
        is_right_valid = self.isValid(node.right, node.val, max_val)
        return is_right_valid

if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    sol = Solution()
    res = sol.isValidBST(root)
    print(res)