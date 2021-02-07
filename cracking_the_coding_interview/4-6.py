class TreeNode(object):
    def __init__(self, val=0, parent=None, left=None, right=None):
        self.val = val
        self.parent = parent
        self.left = left
        self.right = right

def find_next_node(node):
    if node.right:
        return node.right
    
    while node.parent.left != node:
        node = node.parent
    
    return node.parent


