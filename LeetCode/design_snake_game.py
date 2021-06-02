from collections import deque

class SnakeGame:

    def __init__(self, width, height, food):
        self.pos = [0, 0]
        self.food = food
        self.score = 0
        self.body = deque([(0, 0)])
        self.body_set = {(0, 0)}
        self.width = width
        self.height = height
        

    def move(self, direction):
        if direction == 'U':
            self.pos[0] -= 1
        if direction == 'L':
            self.pos[1] -= 1
        if direction == 'R':
            self.pos[1] += 1
        if direction == 'D':
            self.pos[0] += 1
        
        
        if not 0 <= self.pos[0] < self.height or not 0 <= self.pos[1] < self.width:
            return -1
        
        if self.score < len(self.food) and self.pos == self.food[self.score]:
            self.score += 1
            self.body.appendleft(tuple(self.pos))
            self.body_set.add(tuple(self.pos))
            return self.score
        
        prev_pos = self.body.pop()
        self.body_set.remove(prev_pos)
        
        if tuple(self.pos) in self.body_set:
            return -1
        
        self.body.appendleft(tuple(self.pos))
        self.body_set.add(tuple(self.pos))
        
        return self.score