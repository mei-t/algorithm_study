class Solution:
    def solve(self, board):
        if len(board) == 0:
            return
        
        col = len(board[0])
        row = len(board)
        is_visited = [[False for _ in range(col)] for _ in range(row)]
        for i in range(row):
            for j in range(col):
                if is_visited[i][j]:
                    continue
                if board[i][j] == "O" and self.isSurrounded(board, i, j, is_visited):
                    self.flipSurroundedO(board, i, j)
    
    def isSurrounded(self, board, i, j, is_visited):
        col = len(board[0])
        row = len(board)
        if i < 0 or j < 0 or i >= row or j >= col:
            return False
        if board[i][j] == "X" or is_visited[i][j]:
            return True
        is_visited[i][j] = True

        left = self.isSurrounded(board, i-1, j, is_visited)
        up = self.isSurrounded(board, i, j-1, is_visited)
        right = self.isSurrounded(board, i+1, j, is_visited)
        down = self.isSurrounded(board, i, j+1, is_visited)
        return left and up and right and down
    
    def flipSurroundedO(self, board, i, j):
        col = len(board[0])
        row = len(board)
        if i < 0 or j < 0 or i >= row or j >= col:
            return
        if board[i][j] == "X":
            return
        
        board[i][j] = "X"
        self.flipSurroundedO(board, i-1, j)
        self.flipSurroundedO(board, i, j-1)
        self.flipSurroundedO(board, i+1, j)
        self.flipSurroundedO(board, i, j+1)


if __name__ == '__main__':
    sol = Solution()
    board = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"]]
    board2 = [["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]
    board3 = [["O","O","O","O","X","X"],["O","O","O","O","O","O"],["O","X","O","X","O","O"],["O","X","O","O","X","O"],["O","X","O","X","O","O"],["O","X","O","O","O","O"]]
    for row in board3:
        print(row)
    print()
    sol.solve(board3)
    for row in board3:
        print(row)