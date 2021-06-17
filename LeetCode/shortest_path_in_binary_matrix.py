class Solution:
    def shortestPathBinaryMatrix(self, grid):
        if grid[0][0] == 1:
            return -1
        return self.bfs(grid, {(0, 0)}, 1)
    
    def bfs(self, grid, cur, count):
        nexts = set()
        for i, j in cur:
            grid[i][j] = count
            if i == len(grid) - 1 and j == len(grid[0]) - 1:
                return count
            if i > 0 and grid[i - 1][j] == 0:
                nexts.add((i - 1, j))
            if i < len(grid) - 1 and grid[i + 1][j] == 0:
                nexts.add((i + 1, j))
            if j > 0 and grid[i][j - 1] == 0:
                nexts.add((i, j - 1))
            if j < len(grid[0]) - 1 and grid[i][j + 1] == 0:
                nexts.add((i, j + 1))
            if i > 0 and j > 0 and grid[i - 1][j - 1] == 0:
                nexts.add((i - 1, j - 1))
            if i > 0 and j < len(grid[0]) - 1 and grid[i - 1][j + 1] == 0:
                nexts.add((i - 1, j + 1))
            if i < len(grid) - 1 and j > 0 and grid[i + 1][j - 1] == 0:
                nexts.add((i + 1, j - 1))
            if i < len(grid) - 1 and j < len(grid[0]) - 1 and grid[i + 1][j + 1] == 0:
                nexts.add((i + 1, j + 1))
        if not nexts:
            return -1
        return self.bfs(grid, nexts, count + 1)

class Solution2:
    directions = [(-1, -1), (-1, 0), (0, -1), (-1, 1), (1, -1), (1, 1), (1, 0), (0, 1)]
    def shortestPathBinaryMatrix(self, grid):
        if grid[0][0] == 1:
            return -1
        return self.bfs(grid, [(0, 0)], 1)
    
    def bfs(self, grid, cur, count):
        nexts = []
        for i, j in cur:
            if i == len(grid) - 1 and j == len(grid[0]) - 1:
                return count
            for k, l in self.directions:
                x = i + k
                y = j + l
                if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]):
                    continue
                if grid[x][y] == 0:
                    grid[x][y] = count + 1
                    nexts.append((x, y))
        if not nexts:
            return -1
        return self.bfs(grid, nexts, count + 1)