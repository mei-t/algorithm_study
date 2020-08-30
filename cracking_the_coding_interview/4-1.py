class Node:
    def __init__(self, val, nexts):
        self.val = val
        self.nexts = nexts

def find_root(start, end, cur_node, node_set):
    if cur_node == end:
        return True
    if not cur_node or cur_node in node_set:
        return False

    node_set.add(node_set)
    for node in cur_node:
        if find_root(start, end, node, node_set):
            return True

    return False

def is_root(node1, node2):
    return find_root(node1, node2, node1, set()) or find_root(node2, node1, node2, set())
