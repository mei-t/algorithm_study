import copy

class Solution:
    def isRobotBounded(self, instructions):
        direction = [1, 0]
        pos = [0, 0]
        for _ in range(4):
            for c in instructions:
                if c == 'G':
                    pos[0] += direction[0]
                    pos[1] += direction[1]
                if c == 'L':
                    prev = copy.copy(direction)
                    direction[0] = prev[1]
                    direction[1] = -prev[0]
                if c == 'R':
                    prev = copy.copy(direction)
                    direction[0] = -prev[1]
                    direction[1] = prev[0]
            if pos == [0, 0]:
                return True
        
        return False