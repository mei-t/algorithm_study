class Solution(object):
    def maximalSquare(self, matrix):
        dp = [[0 for _ in range(len(matrix[0]) + 1)] for _ in range(len(matrix) + 1)]
        res = 0
        for i in range(1, len(matrix) + 1):
            for j in range(1, len(matrix[0]) + 1):
                if matrix[i - 1][j - 1] == "1":
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1
                    res = max(dp[i][j], res)
                    
        return res * res

class Solution1(object):
    def maximalSquare(self, matrix):
        if not matrix:
            return 0
        res = 0
        i = 0
        while len(matrix) - i > res:
            for j in range(len(matrix[0])):
                if matrix[i][j] == "0":
                    continue
                res = max(res, self.find_square(matrix, i, j))
                
            i += 1
            
        return res * res
        
    def find_square(self, matrix, r, c):
        res = 1
        is_finish = False
        for i in range(min(len(matrix[0]) - c, len(matrix) - r)):
            for j in range(i + 1):
                if matrix[r + i][c + j] == "0":
                    is_finish = True
                    break
                if matrix[r + j][c + i] == "0":
                    is_finish = True
                    break
                if j == i:
                    res = i + 1
            if is_finish:
                break

        return res