def rotate(metrix):
    N = len(matrix)
    for i in range((N + 1) // 2):
        for j in range(N // 2):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[N - j - 1][i]
            matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1]
            matrix[N - i - 1][N - j - 1] = matrix[j][N - i - 1]
            matrix[j][N - i - 1] = tmp

if __name__ == '__main__':
    # matrix = [
    #     [0, 1, 2, 3, 4, 5],
    #     [6, 7, 8, 9, 10, 11],
    #     [12, 13, 14, 15, 16, 17],
    #     [18, 19, 20, 21, 22, 23],
    #     [24, 25, 26, 27, 28, 29],
    #     [30, 31, 32, 33, 34, 35]
    # ]
    matrix = [
        [0, 1, 2, 3, 4],
        [5, 6, 7, 8, 9],
        [10, 11, 12, 13, 14],
        [15, 16, 17, 18, 19],
        [20, 21, 22, 23, 24],
    ]
    rotate(matrix)
    for line in matrix:
        print(line)