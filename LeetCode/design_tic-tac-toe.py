# 13:40
class TicTacToe(object):

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