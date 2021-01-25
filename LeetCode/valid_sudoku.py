class Solution1(object):
    def isValidSudoku(self, board):
        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        sub_set = [set() for _ in range(9)]

        for r in range(9):
            for c in range(9):
                num = board[r][c]
                if num == ".":
                    continue

                i = (r // 3) * 3 + c // 3
                if num in row[c] or num in col[r] or num in sub_set[i]:
                    return False
                
                row[c].add(num)
                col[r].add(num)
                sub_set[i].add(num)
        return True

class Solution(object):
    def isValidSudoku(self, board):
        return self.isValidRow(board) and self.isValidCol(board)\
            and self.isValidSubBox(board)
    
    def isValidRow(self, board):
        for c in range(len(board[0])):
            num_set = set()
            for r in range(len(board)):
                if board[r][c] == ".":
                    continue

                if board[r][c] in num_set:
                    return False
                num_set.add(board[r][c])
        return True
    
    def isValidCol(self, board):
        for r in range(len(board)):
            num_set = set()
            for c in range(len(board[0])):
                if board[r][c] == ".":
                    continue

                if board[r][c] in num_set:
                    return False
                num_set.add(board[r][c])
        return True

    def isValidSubBox(self, board):
        num_sets = [set() for _ in range(9)]
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == ".":
                    continue

                i = (r // 3) * 3 + c // 3
                if board[r][c] in num_sets[i]:
                    return False
                num_sets[i].add(board[r][c])
        return True

if __name__ == "__main__":
    board1 = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    board2 = [
        ["8","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    board3 = [
        [".",".",".","9",".",".",".",".","."],
        [".",".",".",".",".",".",".",".","."],
        [".",".","3",".",".",".",".",".","1"],
        [".",".",".",".",".",".",".",".","."],
        ["1",".",".",".",".",".","3",".","."],
        [".",".",".",".","2",".","6",".","."],
        [".","9",".",".",".",".",".","7","."],
        [".",".",".",".",".",".",".",".","."],
        ["8",".",".","8",".",".",".",".","."]
    ]
    sol = Solution1()
    res = sol.isValidSudoku(board3)
    print(res)