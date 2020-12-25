class Solution1(object):
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

class Solution2(object):
    def spiralOrder(self, matrix):
        if not matrix:
            return []

        R = len(matrix)
        C = len(matrix[0])
        is_visited = [[False for _ in range(C)] for _ in range(R)]
        r_next = [0, 1, 0, -1]
        c_next = [1, 0, -1, 0]
        d = 0
        res = []
        r = c = 0
        for _ in range(R * C):
            res.append(matrix[r][c])
            is_visited[r][c] = True

            r_tmp = r + r_next[d]
            c_tmp = c + c_next[d]
            if 0 <= r_tmp < R and 0 <= c_tmp < C and not is_visited[r_tmp][c_tmp]:
                r, c = r_tmp, c_tmp
            else:
                d = (d + 1) % 4
                r, c = r + r_next[d], c + c_next[d]
        
        return res


if __name__ == '__main__':
    sol = Solution2()
    matrix1 = [[1,2,3],[4,5,6],[7,8,9]]
    matrix2 = [[1, 2, 3, 4],[5, 6, 7, 8],[9, 10, 11, 12]]
    res1 = sol.spiralOrder(matrix1)
    res2 = sol.spiralOrder(matrix2)
    print(res1)
    print(res2)