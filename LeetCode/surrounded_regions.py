class Solution:
    def solve(self, board):
        if board == None:
            return
        
        col = len(board)
        row = len(board[0])
        is_visited = [[False] * row] * col
        print(is_visited)
        for i in range(col):
            for j in range(row):
                if is_visited[i][j]:
                    continue
                # print(i, j)
                # print(is_visited[i][j])
                # # is_visited[i][j] = True
                # print(is_visited)
                if board[i][j] == "O":
                    # is_visited[i][j] = True
                    print(self.flipSurroundedO(board, i, j, is_visited))
    
    def flipSurroundedO(self, board, i, j, is_visited):
        print(i, j)
        col = len(board)
        row = len(board[0])
        if i < 0 or j < 0 or i >= col or j >= row:
            return False
        if board[i][j] == "X" or is_visited[i][j]:
            return True
        is_visited[i][j] = True
        print("AAA")

        if self.flipSurroundedO(board, i-1, j, is_visited) and self.flipSurroundedO(board, i, j-1, is_visited) and self.flipSurroundedO(board, i+1, j, is_visited) and self.flipSurroundedO(board, i, j+1, is_visited):
            print("aaa")
            print(i, j)
            print(board[i][j])
            board[i][j] = "X"
            print(board[i][j])
            for row in board:
                print(row)
            return True
        
        return False


if __name__ == '__main__':
    sol = Solution()
    board = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"]]
    sol.solve(board)
    for row in board:
        print(row)