class Solution:
    def maxArea(self, h, w, horizontalCuts, verticalCuts):
        horizontalCuts.sort()
        verticalCuts.sort()
        horizontalCuts.append(h)
        verticalCuts.append(w)
        
        horiMax = 0
        prev = 0
        for i in range(len(horizontalCuts)):
            cur = horizontalCuts[i] - prev
            horiMax = max(cur, horiMax)
            prev = horizontalCuts[i]
            
        vertMax = 0
        prev = 0
        for j in range(len(verticalCuts)):
            cur = verticalCuts[j] - prev
            vertMax = max(cur, vertMax)
            prev = verticalCuts[j]
        
        return (horiMax * vertMax) % (10 ** 9 + 7)