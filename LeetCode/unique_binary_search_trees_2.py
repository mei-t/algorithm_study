class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def generateTrees(self, n):
        def generateTree(start, end):
            if start > end:
                return [None]
            
            all_trees = []
            
            for i in range(start, end + 1):
                left_trees = generateTree(start, i - 1)
                right_trees = generateTree(i + 1, end)
                
                for left_tree in left_trees:
                    for right_tree in right_trees:
                        node = TreeNode(i)
                        node.left = left_tree
                        node.right = right_tree
                        all_trees.append(node)
            
            return all_trees
        
        return generateTree(1, n)
        