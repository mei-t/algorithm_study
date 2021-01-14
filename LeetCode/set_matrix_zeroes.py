class Solution1(object):
    def setZeroes(self, matrix):
        r_set, c_set = set(), set()
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    r_set.add(i)
                    c_set.add(j)

        for i in r_set:
            for j in range(len(matrix[0])):
                matrix[i][j] = 0
        
        for i in range(len(matrix)):
            for j in c_set:
                matrix[i][j] = 0

class Solution(object):
    def setZeroes(self, matrix):
        if len(matrix) == 0:
            return
        R = len(matrix)
        C = len(matrix[0])
        is_col = False
        for i in range(R):
            if matrix[i][0] == 0:
                is_col = True
            for j in range(1, C):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        
        for i in range(1, R):
            for j in range(1, C):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if matrix[0][0] == 0:
            for j in range(C):
                matrix[0][j] = 0
        
        if is_col:
            for i in range(R):
                matrix[i][0] = 0

if __name__ == '__main__':
    matrix1 = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    matrix2 = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    matrix3 = [[1, 2, 3, 4], [5, 0, 7, 8], [0, 10, 11, 12], [13, 14, 15, 0]]
    matrix4 = [[1, 0]]
    sol = Solution()
    sol.setZeroes(matrix1)
    sol.setZeroes(matrix2)
    sol.setZeroes(matrix3)
    sol.setZeroes(matrix4)
    print(matrix1)
    print(matrix2)
    print(matrix3)
    print(matrix4)