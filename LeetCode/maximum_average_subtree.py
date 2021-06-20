class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maximumAverageSubtree(self, root):
        def traverse(node):
            if not node.left and not node.right:
                return node.val, 1, node.val
            
            l_sum = l_count = l_max = r_sum = r_count = r_max = 0
            if node.left:
                l_sum, l_count, l_max = traverse(node.left)
            
            if node.right:
                r_sum, r_count, r_max = traverse(node.right)
            
            cur_sum = node.val + l_sum + r_sum
            cur_count = l_count + r_count + 1
            cur_ave = cur_sum / cur_count
            return cur_sum, cur_count, max(cur_ave, l_max, r_max)
        
        return traverse(root)[2]