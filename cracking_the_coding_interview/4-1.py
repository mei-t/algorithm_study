class Node:
    def __init__(self, val, nexts):
        self.val = val
        self.nexts = nexts

def find_root(start, end, cur_node):
    if cur_node == end:
        return True
    if not cur_node or cur_node == start:
        return False

    for node in cur_node:
        if find_root(start, end, node):
            return True

    return False

def is_root(node1, node2):
    if node1 == node2:
        return True

    for node in node1.next:
        if find_root(node1, node2, node):
            return True

    for node in node2.next:
        if find_root(node2, node1, node):
            return True

    return False