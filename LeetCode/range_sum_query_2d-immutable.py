
# 5:27
class NumMatrix:

    def __init__(self, matrix):
        self.matrix = matrix
        

    def sumRegion(self, row1, col1, row2, col2):
        res = 0
        for i in range(row1, row2 + 1):
            for j in range(col1, col2 + 1):
                res += self.matrix[i][j]
        
        return res

class NumMatrix2:

    def __init__(self, matrix):
        if not matrix:
            return
        self.matrix = matrix
        self.row_size = len(matrix)
        self.col_size = len(matrix[0])
        self.bit = [[0] * self.col_size for _ in range(self.row_size)]
        for i in range(self.row_size):
            for j in range(self.col_size):
                self.updateBIT(i, j, matrix[i][j])
    
    def lsb(self, i):
        return i & (-i)
    
    def updateBIT(self, r, c, val):
        if val == 0:
            return
        i = r + 1
        while i <= self.row_size:
            j = c + 1
            while j <= self.col_size:
                self.bit[i - 1][j - 1] += val
                j += self.lsb(j)
            i += self.lsb(i)

    def sumRegion(self, row1, col1, row2, col2):
        reg1 = self.sumBIT(row2 + 1, col2 + 1)
        reg2 = self.sumBIT(row1, col1)
        reg3 = self.sumBIT(row1, col2 + 1)
        reg4 = self.sumBIT(row2 + 1, col1)
        return reg1 + reg2 - reg3 - reg4
    
    def sumBIT(self, r, c):
        res = 0
        i = r
        while i > 0:
            j = c
            while j > 0:
                res += self.bit[i - 1][j - 1]
                j -= self.lsb(j)
            i -= self.lsb(i)
        return res