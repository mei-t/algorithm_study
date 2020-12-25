class Solution(object):
    def spiralOrder(self, matrix):
        if len(matrix) == 0:
            return []

        cur_i, cur_j = 0, 0
        bottom, top, left, right = 1, len(matrix), 0, len(matrix[0])
        res = []
        is_first = True

        while True:
            if left == right:
                break
            
            for cur_j in range(left, right):
                res.append(matrix[cur_i][cur_j])
            right -= 1

            if top == bottom:
                break

            for cur_i in range(bottom, top):
                res.append(matrix[cur_i][cur_j])
            top -= 1

            if left == right:
                break
                
            for cur_j in reversed(range(left, right)):
                res.append(matrix[cur_i][cur_j])
            left += 1

            if top == bottom:
                break

            for cur_i in reversed(range(bottom, top)):
                res.append(matrix[cur_i][cur_j])
            bottom += 1
        
        return res

if __name__ == '__main__':
    sol = Solution()
    matrix1 = [[1,2,3],[4,5,6],[7,8,9]]
    matrix2 = [[1, 2, 3, 4],[5, 6, 7, 8],[9, 10, 11, 12]]
    res1 = sol.spiralOrder(matrix1)
    res2 = sol.spiralOrder(matrix2)
    print(res1)
    print(res2)