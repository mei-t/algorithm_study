# 13:40

# TC: O(1)
class TicTacToe(object):

    def __init__(self, n):
        self.rows = [0 for _ in range(n)]
        self.cols = [0 for _ in range(n)]
        self.diagonal = [0, 0]
        self.n = n
        

    def move(self, row, col, player):
        offset = 2 * player - 3
        self.rows[row] += offset
        self.cols[col] += offset
        if row == col:
            self.diagonal[0] += offset
        if row == self.n - col - 1:
            self.diagonal[1] += offset
        if self.rows[row] == self.n or self.cols[col] == self.n or self.n in self.diagonal:
            return 2
        if self.rows[row] == -self.n or self.cols[col] == -self.n or -self.n in self.diagonal:
            return 1
        return 0

# TC: O(n)
class TicTacToe1(object):

    def __init__(self, n):
        self.board = [[0 for _ in range(n)] for _ in range(n)]
        self.n = n
        

    def move(self, row, col, player):
        self.board[row][col] = player
        if self.is_win(row, col, player):
            return player
        return 0
    
    def is_win(self, row, col, player):
        for i in range(self.n):
            if self.board[row][i] != player:
                break
            if i == self.n - 1:
                return True
        
        for i in range(self.n):
            if self.board[i][col] != player:
                break
            if i == self.n - 1:
                return True
        
        if row == col:
            for i in range(self.n):
                if self.board[i][i] != player:
                    break
                if i == self.n - 1:
                    return True
        
        if row == self.n - col - 1:
            for i in range(self.n):
                if self.board[i][self.n - i - 1] != player:
                    break
                if i == self.n - 1:
                    return True
        
        return False