class Solution(object):
    def searchMatrix(self, matrix, target):
        i = -1
        for row in matrix:
            while i + len(row) >= 0 and row[i] > target:
                i -= 1
            if i + len(row) >= 0 and row[i] == target:
                return True

        return False

if __name__ == '__main__':
    sol = Solution()
    matrix = [
      [1,   4,  7, 11, 15],
      [2,   5,  8, 12, 19],
      [3,   6,  9, 16, 22],
      [10, 13, 14, 17, 24],
      [18, 21, 23, 26, 30]
    ]
    print(sol.searchMatrix(matrix, 5))
    print(sol.searchMatrix(matrix, 20))
    matrix = [[-5]]
    print(sol.searchMatrix(matrix, -5))