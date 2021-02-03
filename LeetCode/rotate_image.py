class Solution(object):
    def rotate(self, matrix):
        size = len(matrix) - 1
        for i in range((size + 1) // 2):
            for j in range(i, size - i):
                tmp = matrix[j][i]
                matrix[j][i] = matrix[size - i][j]
                matrix[size - i][j] = matrix[size - j][size - i]
                matrix[size - j][size - i] = matrix[i][size - j]
                matrix[i][size - j] = tmp

if __name__ == '__main__':
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    sol = Solution()
    sol.rotate(matrix)
    for line in matrix:
        print(line)