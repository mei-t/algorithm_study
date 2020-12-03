class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def createNode(nums, left, right):
    if left >= right:
        return None

    mid = (left + right) // 2
    node = TreeNode(nums[mid])
    node.left = createNode(nums, left, mid)
    node.right = createNode(nums, mid + 1, right)
    return node

def createTree(nums):
    return createNode(nums, 0, len(nums))

def output(node):
    if not node:
        return
    output(node.left)
    print(node.val)
    output(node.right)

if __name__ == '__main__':
    nums = [0, 1, 2, 3, 4, 5, 6]
    root = createTree(nums)
    output(root)