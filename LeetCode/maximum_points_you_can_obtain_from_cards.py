# 47:24, TLE
class Solution1:
    def maxScore(self, cardPoints, k):
        size = len(cardPoints) 
        points = [[0] * (size + 1) for _ in range(size + 1)]
        for i in range(1, k + 1):
            for j in range(i + 1):
                if i == 0 and j == 0:
                    continue
                if j == 0:
                    points[j][i - j] = points[j][i - j - 1] + cardPoints[size - i]
                else:
                    points[j][i - j] = points[j - 1][i - j] + cardPoints[j - 1]
        
        res = 0
        for i in range(k + 1):
            res = max(res, points[i][k - i])
        return res

# TLE
class Solution:
    def maxScore(self, cardPoints, k):
        res = 0
        for i in range(k + 1):
            cur = 0
            for j in range(i):
                cur += cardPoints[j]
            for j in range(k - i):
                cur += cardPoints[len(cardPoints) - j - 1]
            res = max(res, cur)
        return res
        