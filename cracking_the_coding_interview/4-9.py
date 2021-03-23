from copy import copy
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def create_list(nodes, cur_list, res):
    if not nodes:
        res.append(cur_list)
        return
    
    length = len(nodes)
    for _ in range(length):
        node = nodes.popleft()
        new_list = copy(cur_list)
        new_list.append(node.val)
        new_nodes = copy(nodes)
        if node.left:
            new_nodes.append(node.left)
        if node.right:
            new_nodes.append(node.right)
        create_list(new_nodes, new_list, res)
        nodes.append(node)

def bst_list(root):
    res = []
    create_list(deque([root]), [], res)
    return res

if __name__ == '__main__':
    node1 = TreeNode(2)
    node2 = TreeNode(1)
    node3 = TreeNode(3)
    root = node1
    node1.left = node2
    node1.right = node3
    res = bst_list(root)
    print(res)