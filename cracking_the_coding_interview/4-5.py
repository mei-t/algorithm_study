import sys

class TreeNode(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def bst_check(root):
    return is_bst(root, -sys.maxsize - 1, sys.maxsize)

def is_bst(node, min_num, max_num):
    if not node:
        return True
    
    if min_num > node.val or max_num < node.val:
        return False

    return is_bst(node.left, min_num, node.val) and is_bst(node.right, node.val, max_num)

def create_tree(nums):
    val = nums.pop(0)
    if val == None:
        return None

    node = TreeNode(val)
    node.left = create_tree(nums)
    node.right = create_tree(nums)
    return node

def output(node):
    if not node:
        return
    print(node.val)
    output(node.left)
    output(node.right)

if __name__ == '__main__':
    nums = [10, 5, 0, None, None, 8, None, None, 20, 15, None, None, 25, None, None]
    root = create_tree(nums)
    # output(root)
    res = bst_check(root)
    print(res)
