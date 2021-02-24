class Solution(object):
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