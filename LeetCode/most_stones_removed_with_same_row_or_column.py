from collections import defaultdict

class Solution:
    def removeStones(self, stones):
        stones = [tuple(stone) for stone in stones]
        dsu = DSU()
        x_map = defaultdict(list)
        y_map = defaultdict(list)
        point_to_idx = dict()
        idx = 0
        for stone in stones:
            x, y = stone[0], stone[1]
            point_to_idx[tuple(stone)] = idx
            if x_map[x] and y_map[y]:
                x_idx = point_to_idx[x_map[x][0]]
                y_idx = point_to_idx[y_map[y][0]]
                dsu.union(x_idx, y_idx)
                dsu.union(idx, x_idx)
            elif x_map[x]:
                x_idx = point_to_idx[x_map[x][0]]
                dsu.union(idx, x_idx)
            elif y_map[y]:
                y_idx = point_to_idx[y_map[y][0]]
                dsu.union(idx, y_idx)
            x_map[x].append(stone)
            y_map[y].append(stone)
            idx += 1
        
        idx_set = set()
        for stone in stones:
            idx = dsu.find(point_to_idx[stone])
            idx_set.add(idx)
        return len(stones) - len(idx_set)

class DSU:
    def __init__(self):
        self.par = list(range(1001))
    
    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        self.par[x] = y