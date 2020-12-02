class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def createNode(nums, i):
    if i >= len(nums):
        return None

    node = TreeNode(nums[i])
    node.left = createNode(nums, i*2+1)
    node.right = createNode(nums, i*2+2)
    return node

def createTree(nums):
    return createNode(nums, 0)

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