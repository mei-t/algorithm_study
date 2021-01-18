class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def buildTree(self, preorder, inorder):
        return self.build(preorder, inorder)
    
    def build(self, preorder, inorder):
        if not inorder:
            return None
        pre_i, in_i = self.findIndex(preorder, inorder)
        print(pre_i, in_i, preorder, inorder)
        node = TreeNode(preorder[pre_i])
        node.left = self.build(preorder[pre_i+1:], inorder[:in_i])
        node.right = self.build(preorder[pre_i+1:], inorder[in_i+1:])
        return node
    
    def findIndex(self, preorder, inorder):
        for i in range(len(preorder)):
            for j in range(len(inorder)):
                if preorder[i] == inorder[j]:
                    return i, j
        
        return None, None

def outputPreorder(node):
    if not node:
        return
    print(node.val)
    outputPreorder(node.left)
    outputPreorder(node.right)

def outputInorder(node):
    if not node:
        return
    outputInorder(node.left)
    print(node.val)
    outputInorder(node.right)

if __name__ == '__main__':
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]
    sol = Solution()
    head = sol.buildTree(preorder, inorder)
    outputPreorder(head)
    print("-------------------------")
    outputInorder(head)