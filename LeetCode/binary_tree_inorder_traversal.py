class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def inorderTraversal(self, root):
        res = []
        self.addNode(root, res)
        return res
    
    def addNode(self, node, res):
        if not node:
            return
        
        self.addNode(node.left, res)
        res.append(node.val)
        self.addNode(node.right, res)

def createTree(nums):
    root = createNode(nums, 0)
    return root

def createNode(nums, i):
    if i >= len(nums):
        return None

    node = TreeNode(nums[i])
    node.left = createNode(nums, i * 2 + 1)
    node.right = createNode(nums, i * 2 + 2)
    return node

def output(node):
    if not node:
        return

    print(node.val)
    output(node.left)
    output(node.right)

if __name__ == '__main__':
    nums = [0, 1, 2, 3, 4, 5, 6]
    root = createTree(nums)
    output(root)
    sol = Solution()
    res = sol.inorderTraversal(root)
    print(res)