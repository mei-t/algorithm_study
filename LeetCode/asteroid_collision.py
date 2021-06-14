class Solution:
    def asteroidCollision(self, asteroids):
        res = []
        tmp = []
        for i in range(len(asteroids)):
            cur = asteroids[i]
            if cur > 0:
                tmp.append(cur)
                continue
                
            if not tmp:
                res.append(cur)
                continue
            
            while True:
                prev = tmp.pop()
                if prev == abs(cur):
                    break
                if prev > abs(cur):
                    tmp.append(prev)
                    break
                if not tmp:
                    res.append(cur)
                    break
                    
        res.extend(tmp)
        return res
                
        