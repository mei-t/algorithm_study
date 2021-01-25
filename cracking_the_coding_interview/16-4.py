class Result(object):
    def __init__(self, is_draw, winner=""):
        self.is_draw = is_draw
        self.winner = winner

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

if __name__ == "__main__":
    # matrix = ["ooo", "oxx", "xox"]
    # matrix = ["oxo", "oxx", "xxo"]
    # matrix = ["oxo", "xox", "oxx"]
    matrix = ["oxo", "xox", "xox"]
    res = judge(matrix)
    print(res.is_draw, res.winner)