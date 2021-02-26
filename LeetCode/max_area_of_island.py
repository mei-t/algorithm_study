# 19:42
class Solution:
    def maxAreaOfIsland(self, grid):
        if not grid:
            return 0
        visited = [[False] * len(grid[0]) for _ in range(len(grid))]
        max_area = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] and not visited[i][j]:
                    max_area = max(self.checkIsland(grid, i, j, visited), max_area)
        
        return max_area
    
    def checkIsland(self, grid, i, j, visited):
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
            return 0
        
        if visited[i][j] or not grid[i][j]:
            return 0
        
        visited[i][j] = True
        ans = 1
        ans += self.checkIsland(grid, i + 1, j, visited)
        ans += self.checkIsland(grid, i, j + 1, visited)
        ans += self.checkIsland(grid, i - 1, j, visited)
        ans += self.checkIsland(grid, i, j - 1, visited)
        return ans