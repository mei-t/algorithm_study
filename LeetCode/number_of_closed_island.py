# 11:14
class Solution:
    def closedIsland(self, grid):
        def helper(i, j):
            if i < 0 or  i >= len(grid) or j < 0 or j >= len(grid[0]):
                return 0
            
            if grid[i][j]:
                return 1
            
            grid[i][j] = 1
            a1 = helper(i - 1, j)
            a2 = helper(i, j - 1)
            a3 = helper(i + 1, j)
            a4 = helper(i, j + 1)
            return a1 and a2 and a3 and a4
        
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    continue
                res += helper(i, j)
        return res