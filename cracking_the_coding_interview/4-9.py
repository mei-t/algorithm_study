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

def bst_list2(root):
    res = []
    if not root:
        res.append(deque([]))
        return res
    
    prefix = deque([root.val])
    left_seq = bst_list2(root.left)
    right_seq = bst_list2(root.right)

    for left in left_seq:
        for right in right_seq:
            weaved = deque([])
            weave_list(left, right, weaved, prefix)
            res.extend(weaved)
    
    return res

def weave_list(left, right, weaved, prefix):
    if len(left) == 0 or len(right) == 0:
        res = copy(prefix)
        res.extend(left)
        res.extend(right)
        weaved.append(res)
        return
    
    head_left = left.popleft()
    prefix.append(head_left)
    weave_list(left, right, weaved, prefix)
    prefix.pop()
    left.appendleft(head_left)

    head_right = right.popleft()
    prefix.append(head_right)
    weave_list(left, right, weaved, prefix)
    prefix.pop()
    left.appendleft(head_left)

if __name__ == '__main__':
    node1 = TreeNode(2)
    node2 = TreeNode(1)
    node3 = TreeNode(3)
    root = node1
    node1.left = node2
    node1.right = node3
    res = bst_list2(root)
    print(res)