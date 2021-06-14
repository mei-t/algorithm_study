# TLE
class Solution:
    def hasPath(self, maze, start, destination):
        new_maze = [[0] * (len(maze[0]) + 2) for _ in range(len(maze) + 2)]
        for i in range(len(maze[0]) + 2):
            new_maze[0][i] = 1
            new_maze[len(maze) + 1][i] = 1
        for i in range(len(maze) + 2):
            new_maze[i][0] = 1
            new_maze[i][len(maze[0]) + 1] = 1
        for i in range(1, len(maze) + 1):
            for j in range(1, len(maze[0]) + 1):
                new_maze[i][j] = maze[i - 1][j - 1]
        visited = set()
        start[0] += 1
        start[1] += 1
        destination[0] += 1
        destination[1] += 1
        return self.findPath(new_maze, start, destination, [0, 0], visited)
    
    def findPath(self, maze, start, cur, direction, visited):
        if cur == start:
            return True
        if tuple(cur + direction) in visited:
            return False
        
        visited.add(tuple(cur + direction))
        
        if maze[cur[0] + 1][cur[1]] == 0 and maze[cur[0] - 1][cur[1]] == 1:
            if self.findPath(maze, start, [cur[0] + 1, cur[1]], [1, 0], visited):
                return True
            
        if maze[cur[0] - 1][cur[1]] == 0 and maze[cur[0] + 1][cur[1]] == 1:
            if self.findPath(maze, start, [cur[0] - 1, cur[1]], [-1, 0], visited):
                return True
            
        if maze[cur[0]][cur[1] + 1] == 0 and maze[cur[0]][cur[1] - 1] == 1:
            if self.findPath(maze, start, [cur[0], cur[1] + 1], [0, 1], visited):
                return True
        
        if maze[cur[0]][cur[1] - 1] == 0 and maze[cur[0]][cur[1] + 1] == 1:
            if self.findPath(maze, start, [cur[0], cur[1] - 1], [0, -1], visited):
                return True
        
        if direction != [0, 0] and maze[cur[0] + direction[0]][cur[1] + direction[1]] == 0:
            if self.findPath(maze, start, [cur[0] + direction[0], cur[1] + direction[1]], direction, visited):
                return True
        
        visited.remove(tuple(cur + direction))
        return False
            
# Accepted
class Solution2:
    def hasPath(self, maze, start, destination):
        new_maze = [[0] * (len(maze[0]) + 2) for _ in range(len(maze) + 2)]
        for i in range(len(maze[0]) + 2):
            new_maze[0][i] = 1
            new_maze[len(maze) + 1][i] = 1
        for i in range(len(maze) + 2):
            new_maze[i][0] = 1
            new_maze[i][len(maze[0]) + 1] = 1
        for i in range(1, len(maze) + 1):
            for j in range(1, len(maze[0]) + 1):
                new_maze[i][j] = maze[i - 1][j - 1]
        visited = set()
        start[0] += 1
        start[1] += 1
        destination[0] += 1
        destination[1] += 1
        visited = [[0] * (len(maze[0]) + 2) for _ in range(len(maze) + 2)] 
        return self.findPath(new_maze, start, destination, visited)
    
    def findPath(self, maze, cur, destination, visited):
        if cur == destination:
            return True
        if visited[cur[0]][cur[1]]:
            return False
        
        visited[cur[0]][cur[1]] = 1
        
        u, d, l, r = cur[0], cur[0], cur[1], cur[1]
        
        while maze[u + 1][cur[1]] == 0:
            u += 1
        if self.findPath(maze, [u, cur[1]], destination, visited):
            return True
        
        while maze[d - 1][cur[1]] == 0:
            d -= 1
        if self.findPath(maze, [d, cur[1]], destination, visited):
            return True
        
        while maze[cur[0]][l - 1] == 0:
            l -= 1
        if self.findPath(maze, [cur[0], l], destination, visited):
            return True
        
        
        while maze[cur[0]][r + 1] == 0:
            r += 1
        if self.findPath(maze, [cur[0], r], destination, visited):
            return True
        
        return False
        