class Solution:
    def minimumCost(self, n, connections):
        connections.sort(key=lambda x: x[2])
        ds = DisjointSet(n)
        cost = 0
        total = 1
        for i in range(len(connections)):
            a, b, weight = connections[i]
            if ds.isInSameGroup(a, b):
                continue
            ds.union(a, b)
            cost += weight
            total += 1
        
        if total == n:
            return cost
        return -1
            
        
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.weight = [1] * (n + 1)
    
    def find(self, a):
        while a != self.parent[a]:
            self.parent[a] = self.parent[self.parent[a]]
            a = self.parent[a]
        
        return a
    
    def union(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        
        if root_a == root_b:
            return
        
        if self.weight[root_a] > self.weight[root_b]:
            self.parent[root_b] = root_a
            self.weight[root_a] += self.weight[root_b]
            return
        
        self.parent[root_a] = root_b
        self.weight[root_b] += self.weight[root_a]
    
    def isInSameGroup(self, a, b):
        return self.find(a) == self.find(b)
    
        