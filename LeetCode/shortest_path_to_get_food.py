class Solution:
    def getFood(self, grid):
        def bfs(grid, positions, length):
            tmps = [[0, -1], [-1, 0], [0, 1], [1, 0]]
            next_pos = []
            for pos in positions:
                for tmp in tmps:
                    i = pos[0] + tmp[0]
                    j = pos[1] + tmp[1]
                    if not 0 <= i < len(grid) or not 0 <= j < len(grid[0]):
                        continue
                    if grid[i][j] == '#':
                        return length
                    if grid[i][j] == 'O':
                        grid[i][j] = '*'
                        next_pos.append([i, j])
            
            if not next_pos:
                return -1
            return bfs(grid, next_pos, length + 1)
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '*':
                    return bfs(grid, [[i, j]], 1)
        