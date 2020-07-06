import unittest

class Solution:
    def exist(self, board, word):
        if len(board) == 0:
            return word == 0

        print("start")
        for i in range(len(board)):
            for j in range(len(board[0])):
                # import pdb; pdb.set_trace()
                print(board[i][j])
                if word[0] == board[i][j]:
                    print("word[0] == board[i][j]")
                    if self.findStr(board, word, i, j, 0, set()):
                        return True

        return False
    

    def findStr(self, board, word, i, j, index, posSet):
        if index == len(word):
            return True
        if i >= len(board) or j >= len(board[0]) or i < 0 or j < 0:
            return False
        if  (j * len(board[0]) + i) in posSet or word[index] != board[i][j]:
            return False
        
        posSet.add(j * len(board[0]) + i)
        up = self.findStr(board, word, i - 1, j, index + 1, posSet)
        if up:
            return True
        left = self.findStr(board, word, i, j - 1, index + 1, posSet)
        if left:
            return True
        down = self.findStr(board, word, i + 1, j, index + 1, posSet)
        if down:
            return True
        right = self.findStr(board, word, i, j + 1, index + 1, posSet)
        return right


class Test(unittest.TestCase):
    board = [
        ["A","B","C","E"],
        ["S","F","C","S"],
        ["A","D","E","E"]
    ]
    word = "ABCCED"

    def test(self):
        sol = Solution()
        self.assertTrue(sol.exist(self.board, self.word))


if __name__ == '__main__':
    unittest.main()