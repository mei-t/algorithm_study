class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def levelOrder(self, root):
        return self.addValueByLevel(root, 0, [])
    
    def addValueByLevel(self, node, depth, res):
        if not node:
            return res
        
        if depth >= len(res):
            res.append([])
        res[depth].append(node.val)

        self.addValueByLevel(node.left, depth + 1, res)
        self.addValueByLevel(node.right, depth + 1, res)
        return res

def createTree(nums, i):
    if i >= len(nums) or not nums[i]:
        return None
    node = TreeNode(nums[i])
    node.left = createTree(nums, i * 2 + 1)
    node.right = createTree(nums, i * 2 + 2)
    return node

if __name__ == '__main__':
    nums = [3, 9, 20, None, None, 15, 7]
    root = createTree(nums, 0)
    sol = Solution()
    res = sol.levelOrder(root)
    print(res)