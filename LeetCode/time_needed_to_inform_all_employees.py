from collections import deque
# 37:25

class Solution(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        def computeMinutes(i):
            if manager[i] != -1:
                informTime[i] += computeMinutes(manager[i])
                manager[i] = -1
            return informTime[i]
        return max(map(computeMinutes, range(n)))

class Solution2(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        children = [[] for _ in range(n)]
        for i, m in enumerate(manager):
            if m != -1:
                children[m].append(i)
            
        def computeMinutes(i):
            return max([computeMinutes(j) for j in children[i]] or [0]) + informTime[i]
        
        return computeMinutes(headID)

# Time limit exceeded
class Solution1(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        if n <= 1:
            return 0
        return self.calculateMinutes(headID, manager, informTime)
        
        
    def calculateMinutes(self, id, manager, informTime):
        q = deque()
        for i, m in enumerate(manager):
            if m == id:
                q.append(i)
        
        max_time = 0
        while q:
            e = q.pop()
            time = self.calculateMinutes(e, manager, informTime)
            if time > max_time:
                max_time = time
        
        return max_time + informTime[id]

if __name__ == '__main__':
    sol = Solution()
    manager = [-1,5,0,6,7,0,0,0]
    informTime = [89,0,0,0,0,523,241,519]
    res = sol.numOfMinutes(8, 0, manager, informTime)
    print(res)
