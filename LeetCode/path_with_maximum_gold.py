# 22:34
class Solution1:
    def getMaximumGold(self, grid):
        def helper(i, j, pos_set):
            if not 0 <= i < len(grid) or not 0 <= j < len(grid[0]):
                return 0
            if (i, j) in pos_set or grid[i][j] == 0:
                return 0
            pos_set.add((i, j))
            g1 = helper(i - 1, j, pos_set)
            g2 = helper(i, j - 1, pos_set)
            g3 = helper(i + 1, j, pos_set)
            g4 = helper(i, j + 1, pos_set)
            pos_set.discard((i, j))
            return max(g1, g2, g3, g4) + grid[i][j]
            
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    continue
                res = max(res, helper(i, j, set()))
        return res

class Solution:
    def getMaximumGold(self, grid):
        def helper(i, j):
            if not 0 <= i < len(grid) or not 0 <= j < len(grid[0]):
                return 0
            if grid[i][j] == 0:
                return 0
            tmp = grid[i][j]
            grid[i][j] = 0
            g1 = helper(i - 1, j)
            g2 = helper(i, j - 1)
            g3 = helper(i + 1, j)
            g4 = helper(i, j + 1)
            grid[i][j] = tmp
            return max(g1, g2, g3, g4) + grid[i][j]
            
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    continue
                res = max(res, helper(i, j))
        return res