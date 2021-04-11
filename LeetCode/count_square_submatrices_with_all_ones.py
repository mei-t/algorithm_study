# 28:15
class Solution1:
    def countSquares(self, matrix):
        def helper(r, c, l):
            res = 0
            for i in range(l):
                if r + l - 1 >= len(matrix) or c + l - 1 >= len(matrix[0]):
                    break
                if matrix[r + i][c + l - 1] == 0 or matrix[r + l - 1][c + i] == 0:
                    break
                if i == l - 1:
                    res = 1 + helper(r, c, l + 1)
            return res
        
        res = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    continue
                res += helper(i, j, 1)
        return res

class Solution:
    def countSquares(self, matrix):
        res = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    continue
                
                if i == 0 or j == 0:
                    res += 1
                    continue
                
                tmp = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1])
                matrix[i][j] = tmp + 1
                res += tmp + 1
        
        return res