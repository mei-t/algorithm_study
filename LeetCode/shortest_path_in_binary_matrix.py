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