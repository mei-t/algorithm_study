class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
class LinkedNone:
    def __init__(self, val, next_node=None):
        self.val = val
        self.next = next_node

def createDepthList(node, res, cur, depth):
    if not node:
        return res
    
    lnode = LinkedNone(node.val)
    if depth >= len(res):
        res.append(lnode)
        cur.append(lnode)
    else:
        cur[depth].next = lnode
        cur[depth] = lnode
    
    createDepthList(node.left, res, cur, depth + 1)
    createDepthList(node.right, res, cur, depth + 1)
    return res

def depthList(root):
    res, cur = [], []
    return createDepthList(root, res, cur, 0)

if __name__ == '__main__':
    tn1 = TreeNode(8)
    tn2 = TreeNode(4)
    tn3 = TreeNode(12)
    tn4 = TreeNode(2)
    tn5 = TreeNode(10)
    tn6 = TreeNode(16)
    tn1.left = tn2
    tn1.right = tn3
    tn2.left = tn4
    tn3.left = tn5
    tn3.right = tn6
    res = depthList(tn1)
    for ln in res:
        while ln:
            print(ln.val)
            ln = ln.next
        print()