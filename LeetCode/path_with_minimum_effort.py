import heapq

# 31:23
# TLE
class Solution1:
    def minimumEffortPath(self, heights):
        def helper(i, j, prev):
            if not 0 <= i < len(heights) or not 0 <= j < len(heights[0]):
                return float('inf')
            if heights[i][j] == 0:
                return float('inf')
            if i == len(heights) - 1 and j == len(heights[0]) - 1:
                return abs(prev - heights[i][j])
            
            tmp = heights[i][j]
            heights[i][j] = 0
            up = helper(i - 1, j, tmp)
            right = helper(i, j - 1, tmp)
            down = helper(i + 1, j, tmp)
            left = helper(i, j + 1, tmp)
            heights[i][j] = tmp
            return max(min(up, right, down, left), abs(tmp - prev))
        
        if not heights:
            return 0
        return helper(0, 0, heights[0][0])

# Accepted
class Solution2:
    def minimumEffortPath(self, heights):
        if not heights:
            return 0
        diffs = [[float('inf')] * len(heights[0]) for _ in range(len(heights))]
        visited = set()
        q = []
        heapq.heappush(q, [0, (0, 0)])
        
        while q:
            node = heapq.heappop(q)
            if node[1] in visited:
                continue
            visited.add(node[1])
            i, j = node[1]
            diffs[i][j] = node[0]
            if i == len(heights) - 1 and j == len(heights[0]) - 1:
                break
            
            if 0 <= i - 1 and (i - 1, j) not in visited:
                new_node = [max(node[0], abs(heights[i][j] - heights[i - 1][j])), (i - 1, j)]
                heapq.heappush(q, new_node)
            if 0 <= j - 1 and (i, j - 1) not in visited:
                new_node = [max(node[0], abs(heights[i][j] - heights[i][j - 1])), (i, j - 1)]
                heapq.heappush(q, new_node)
            if i + 1 < len(heights) and (i + 1, j) not in visited:
                new_node = [max(node[0], abs(heights[i][j] - heights[i + 1][j])), (i + 1, j)]
                heapq.heappush(q, new_node)
            if j + 1 < len(heights[0]) and (i, j + 1) not in visited:
                new_node = [max(node[0], abs(heights[i][j] - heights[i][j + 1])), (i, j + 1)]
                heapq.heappush(q, new_node)
        
        return diffs[-1][-1]

# Accepted (Union Find)
class Solution:
    def minimumEffortPath(self, heights):
        class UnionFind:
            def __init__(self, size):
                self.parent = list(range(size))
            
            def find(self, x):
                if self.parent[x] != x:
                    self.parent[x] = self.find(self.parent[x])
                return self.parent[x]
            
            def union(self, x, y):
                parent_x = self.find(x)
                parent_y = self.find(y)
                if parent_x != parent_y:
                    self.parent[parent_x] = parent_y
        
        row, col = len(heights), len(heights[0])
        if row == 1 and col == 1:
            return 0
        edge_list = []
        for i in range(row):
            for j in range(col):
                if i > 0:
                    diff = abs(heights[i][j] - heights[i - 1][j])
                    edge_list.append((diff, i * col + j, (i - 1) * col + j))
                if j > 0:
                    diff = abs(heights[i][j] - heights[i][j - 1])
                    edge_list.append((diff, i * col + j, i * col + j - 1))
        edge_list.sort()
        uf = UnionFind(row * col)
        for diff, x, y in edge_list:
            uf.union(x, y)
            if uf.find(0) == uf.find(row * col - 1):
                return diff
        return -1
        