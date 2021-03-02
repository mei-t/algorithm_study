def change_to_zero(matrix):
    if not matrix:
        return
    is_row_zero, is_col_zero = False, False
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
                if i == 0:
                    is_row_zero = True
                if j == 0:
                    is_col_zero = True

    for i in range(1, len(matrix)):
        if matrix[i][0] == 0:
            for j in range(len(matrix[0])):
                matrix[i][j] = 0
    for j in range(1, len(matrix[0])):
        if matrix[0][j] == 0:
            for i in range(len(matrix)):
                matrix[i][j] = 0
    if is_row_zero:
        for j in range(len(matrix[0])):
            matrix[0][j] = 0
    if is_col_zero:
        for i in range(len(matrix)):
            matrix[i][0] = 0

if __name__ == '__main__':
    matrix = [
        [3, 24, 0, 8],
        [4, 5, 12, 3],
        [8, 0, 11, 2],
        [5, 7, 8, 9]
    ]
    change_to_zero(matrix)
    for line in matrix:
        print(line)