class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_balance_tree(node):
    res = check_balance_tree(node)
    return True if res > 0 else False

def check_balance_tree(node):
    if not node:
        return 0
    
    left_depth = check_balance_tree(node.left)
    if left_depth == -1:
        return -1
    right_depth = check_balance_tree(node.right)
    if right_depth == -1:
        return -1
    if abs(left_depth - right_depth) > 1:
        return -1
    
    return max(left_depth, right_depth) + 1

if __name__ == "__main__":
    node_0 = TreeNode(0)
    node_1 = TreeNode(1)
    node_2 = TreeNode(2)
    node_3 = TreeNode(3)
    node_4 = TreeNode(4)
    node_5 = TreeNode(5)
    node_0.left = node_1
    node_0.right = node_2
    node_1.left = node_3
    node_1.right = node_4
    node_3.left = node_5
    print(is_balance_tree(node_0))