import unittest

def rotate(matrix):
    N = len(matrix)
    for i in range((N + 1) // 2):
        for j in range(N // 2):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[N - j - 1][i]
            matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1]
            matrix[N - i - 1][N - j - 1] = matrix[j][N - i - 1]
            matrix[j][N - i - 1] = tmp

class Test(unittest.TestCase):
    def test_even(self):
        matrix = [
            [0, 1, 2, 3, 4, 5],
            [6, 7, 8, 9, 10, 11],
            [12, 13, 14, 15, 16, 17],
            [18, 19, 20, 21, 22, 23],
            [24, 25, 26, 27, 28, 29],
            [30, 31, 32, 33, 34, 35]
        ]
        expected = [
            [30, 24, 18, 12, 6, 0],
            [31, 25, 19, 13, 7, 1],
            [32, 26, 20, 14, 8, 2],
            [33, 27, 21, 15, 9, 3],
            [34, 28, 22, 16, 10, 4],
            [35, 29, 23, 17, 11, 5]
        ]
        rotate(matrix)
        self.assertEquals(matrix, expected)

    def test_odd(self):
        matrix = [
            [0, 1, 2, 3, 4],
            [5, 6, 7, 8, 9],
            [10, 11, 12, 13, 14],
            [15, 16, 17, 18, 19],
            [20, 21, 22, 23, 24]
        ]
        expected = [
            [20, 15, 10, 5, 0],
            [21, 16, 11, 6, 1],
            [22, 17, 12, 7, 2],
            [23, 18, 13, 8, 3],
            [24, 19, 14, 9, 4]
        ]
        rotate(matrix)
        self.assertEquals(matrix, expected)

if __name__ == '__main__':
    unittest.main()