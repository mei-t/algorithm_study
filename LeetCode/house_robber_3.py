from collections import defaultdict, deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rob(self, root):
        graph = defaultdict(list)
        tree = defaultdict()
        q = deque([(root, -1)])
        index = -1
        while q:
            node, parent_index = q.popleft()
            if node:
                index += 1
                graph[parent_index].append(index)
                tree[index] = node
                q.append((node.left, index))
                q.append((node.right, index))
        
        dp_rob = [0] * (index + 1)
        dp_not_rob = [0] * (index + 1)
        
        for i in reversed(range(index + 1)):
            dp_rob[i] = tree[i].val + sum(dp_not_rob[j] for j in graph[i])
            dp_not_rob[i] = sum(max(dp_rob[j], dp_not_rob[j]) for j in graph[i])
        
        return max(dp_rob[0], dp_not_rob[0])

class Solution2:
    def rob(self, root):
        def check(node):
            if not node:
                return (0, 0)
            left = check(node.left)
            right = check(node.right)
            
            rob_cur = node.val + left[1] + right[1]
            not_rob_cur = max(left) + max(right)
            return (rob_cur, not_rob_cur)
        return max(check(root))

class Solution1:
    def rob(self, root):
        return self.check(root, True, dict())
    
    def check(self, node, can_take, node_map):
        if not node:
            return 0
        
        if (node, can_take) in node_map:
            return node_map[node, can_take]
        rob_cur = 0
        if can_take:
            rob_cur = node.val + self.check(node.left, False, node_map) + self.check(node.right, False, node_map)
        rob_next = self.check(node.left, True, node_map) + self.check(node.right, True, node_map)
        res = max(rob_cur, rob_next)
        node_map[node, can_take] = res
        return res