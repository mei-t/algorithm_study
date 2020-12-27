import heapq

class Solution(object):
    def kthSmallest(self, matrix, k):
        R, C = len(matrix), len(matrix[0])
        h = []
        screen = [[False for _ in range(C)] for _ in range(R)]
        x = (matrix[0][0], 0, 0)
        heapq.heappush(h, x)
        screen[0][0] = True
        while k > 0:
            x = heapq.heappop(h)
            k -= 1
            r = x[1]
            c = x[2]
            if r + 1 < R and c < C and not screen[r + 1][c]:
                heapq.heappush(h, (matrix[r + 1][c], r + 1, c))
                screen[r + 1][c] = True

            if r < R and c + 1 < C and not screen[r][c + 1]:
                heapq.heappush(h, (matrix[r][c + 1], r, c + 1))
                screen[r][c + 1] = True

        return x[0]

if __name__ == '__main__':
    sol = Solution()
    matrix = [
       [ 1,  5,  9],
       [10, 11, 13],
       [12, 13, 15]
    ]
    k = 8
    res = sol.kthSmallest(matrix, k)
    print(res)