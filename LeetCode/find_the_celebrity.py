graph = []

def knows(a, b):
    return graph[a][b]

class Solution(object):
    def findCelebrity(self, n):
        cand = 0
        for i in range(1, n):
            if knows(cand, i):
                cand = i
                
        for i in range(n):
            if cand == i:
                continue
            if knows(cand, i):
                return -1
            if not knows(i, cand):
                return -1
        
        return cand

if __name__ == '__main__':
    graph = [[1,1,0],[0,1,0],[1,1,1]]
    sol = Solution()
    res = sol.findCelebrity(3)
    print(res)