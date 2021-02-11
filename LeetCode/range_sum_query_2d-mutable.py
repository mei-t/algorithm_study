
# init: O(N * M * logN * logM)
# update, query: O(logN * logM)
class NumMatrix(object):

    def __init__(self, matrix):
        if not matrix:
            return
        self.matrix = matrix
        self.bit = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        self.row_size = len(matrix)
        self.col_size = len(matrix[0])
        for i in range(1, self.row_size + 1):
            for j in range(1, self.col_size + 1):
                self.updateBIT(i, j, matrix[i - 1][j - 1])
    
    def lsb(self, i):
        return i & (-i)
        
    def updateBIT(self, r, c, val):
        if val == 0:
            return
        i = r
        while i <= self.row_size:
            j = c
            while j <= self.col_size:
                self.bit[i - 1][j - 1] += val
                j += self.lsb(j)
            i += self.lsb(i)
                
    def queryBIT(self, r, c):
        res = 0
        i = r
        while i > 0:
            j = c
            while j > 0:
                res += self.bit[i - 1][j - 1]
                j -= self.lsb(j)
            i -= self.lsb(i)    
            
        return res
        

    def update(self, row, col, val):
        orig = self.matrix[row][col]
        self.updateBIT(row + 1, col + 1, val - orig)
        self.matrix[row][col] = val

    def sumRegion(self, row1, col1, row2, col2):
        sum1 = self.queryBIT(row2 + 1, col2 + 1)
        sum2 = self.queryBIT(row1, col1)
        sum3 = self.queryBIT(row1, col2 + 1)
        sum4 = self.queryBIT(row2 + 1, col1)
        return sum1 + sum2 - sum3 - sum4

# sumRegion: O(N * M)
# update: O(1)
class NumMatrix1(object):

    def __init__(self, matrix):
        self.matrix = matrix
        self.rect_map = dict()
        

    def update(self, row, col, val):
        self.matrix[row][col] = val

    def sumRegion(self, row1, col1, row2, col2):
        res = 0
        for i in range(row1, row2 + 1):
            for j in range(col1, col2 + 1):
                res += self.matrix[i][j]
        return res

# sumRegion: O(N * M)
# update: O(1)
class NumMatrix2(object):

    def __init__(self, matrix):
        self.matrix = matrix
        self.rect_map = dict()
        

    def update(self, row, col, val):
        tmp = self.matrix[row][col]
        self.matrix[row][col] = val
        for key in self.rect_map:
            if key[0] <= row and key[1] <= col and row <= key[2] and col <= key[3]:
                self.rect_map[key] += val - tmp
        

    def sumRegion(self, row1, col1, row2, col2):
        key = (row1, col1, row2, col2)
        if key in self.rect_map:
            return self.rect_map[key]
        
        res = 0
        for i in range(row1, row2 + 1):
            for j in range(col1, col2 + 1):
                res += self.matrix[i][j]
        self.rect_map[key] = res
        return res