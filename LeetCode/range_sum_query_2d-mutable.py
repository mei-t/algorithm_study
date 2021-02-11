
class NumMatrix(object):

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