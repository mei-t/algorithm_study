from collections import defaultdict, Counter

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDuplicateSubtrees(self, root):
        res = []
        node_map = Counter()
        def search(node):
            if not node:
                return '#'
            tmp = '{}, {}, {}'.format(node.val, search(node.left), search(node.right))
            node_map[tmp] += 1
            if node_map[tmp] == 2:
                res.append(node)
            return tmp
        
        search(root)
        return res

# Wrong answer
class Solution1:
    def findDuplicateSubtrees(self, root):
        depth_map = defaultdict(list)
        self.create_depth_map(root, depth_map)
        
        res = []
        visited = set()
        for depth in range(len(depth_map) - 1, -1, -1):
            nodes = depth_map[depth]
            for i in range(len(nodes)):
                if nodes[i] in visited:
                    continue
                for j in range(i + 1, len(nodes)):
                    if nodes[j] in visited:
                        continue
                    self.is_same(nodes[i], nodes[j], res, visited)
        return res
    
    def create_depth_map(self, node, depth_map):
        if not node:
            return 0
        left_depth = self.create_depth_map(node.left, depth_map)
        right_depth = self.create_depth_map(node.right, depth_map)
        depth = max(left_depth, right_depth)
        depth_map[depth].append(node)
        return depth + 1
    
    def is_same(self, node1, node2, res, visited):
        if not node1 and not node2:
            return True
        if not node1 or not node2 or node1.val != node2.val:
            return False
        if not self.is_same(node1.left, node2.left, res, visited) or not self.is_same(node1.right, node2.right, res, visited):
            return False
        res.append(node1)
        visited.add(node1)
        visited.add(node2)
        return True
    