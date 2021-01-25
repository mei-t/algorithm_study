import unittest

class Result(object):
    def __init__(self, is_draw, winner=""):
        self.is_draw = is_draw
        self.winner = winner

# 解法2
def judge2(matrix):
    if has_won(matrix, "o"):
        return Result(False, "o")
    elif has_won(matrix, "x"):
        return Result(False, "x")
    return Result(True)

def has_won(matrix, player):
    size = len(matrix)
    for i in range(size):
        for j in range(size):
            if matrix[i][j] != player:
                break
            if j == size - 1:
                return True
        
        for j in range(size):
            if matrix[j][i] != player:
                break
            if j == size - 1:
                return True
    
    for i in range(size):
        if matrix[i][i] != player:
            break
        if i == size - 1:
            return True
    
    for i in range(size):
        if matrix[i][size - 1 - i] != player:
            break
        if i == size - 1:
            return True
    
    return False

# 解法1
def judge(matrix):
    row = check_row(matrix)
    if not row.is_draw:
        return row
    
    col = check_col(matrix)
    if not col.is_draw:
        return col
    
    diago = check_diago(matrix)
    return diago

def check_row(matrix):
    for i in range(3):
        if matrix[i][0] == matrix[i][1] and matrix[i][0] == matrix[i][2]:
            return Result(False, matrix[i][0])
    return Result(True)

def check_col(matrix):
    for i in range(3):
        if matrix[0][i] == matrix[1][i] and matrix[0][i] == matrix[2][i]:
            return Result(False, matrix[0][i])
    return Result(True)

def check_diago(matrix):
    for i in range(2):
        if matrix[i][i] != matrix[i+1][i+1]:
            break
        if i == 1:
            return Result(False, matrix[i][i])
    
    for i in range(2):
        if matrix[i][2-i] != matrix[i+1][1-i]:
            break
        if i == 1:
            return Result(False, matrix[i][2-i])
    return Result(True)

class Test(unittest.TestCase):
    def test_draw(self):
        matrix = ["oxo", "xox", "xox"]
        res = judge2(matrix)
        self.assertEqual(res.is_draw, True)
    
    def test_row(self):
        matrix = ["ooo", "oxx", "xox"]
        res = judge2(matrix)
        self.assertEqual(res.is_draw, False)
        self.assertEqual(res.winner, "o")
    
    def test_col(self):
        matrix = ["oxo", "oxx", "xxo"]
        res = judge2(matrix)
        self.assertEqual(res.is_draw, False)
        self.assertEqual(res.winner, "x")
    
    def test_diago(self):
        matrix = ["oxo", "xox", "oxx"]
        res = judge2(matrix)
        self.assertEqual(res.is_draw, False)
        self.assertEqual(res.winner, "o")


if __name__ == "__main__":
    unittest.main()