import unittest

class Solution:
    def exist(self, board, word):
        if len(board) == 0:
            return word == 0

        for i in range(len(board)):
            for j in range(len(board[0])):
                if word[0] == board[i][j]:
                    if self.findStr(board, word, i, j, 0, set()):
                        return True

        return False
    

    def findStr(self, board, word, i, j, index, posSet):
        if index == len(word):
            return True
        if i >= len(board) or j >= len(board[0]) or i < 0 or j < 0:
            return False
        if  str(i) + " " + str(j) in posSet or word[index] != board[i][j]:
            return False
        
        posSet.add(str(i) + " " + str(j))
        up = self.findStr(board, word, i - 1, j, index + 1, posSet.copy())
        if up:
            return True
        left = self.findStr(board, word, i, j - 1, index + 1, posSet.copy())
        if left:
            return True
        down = self.findStr(board, word, i + 1, j, index + 1, posSet.copy())
        if down:
            return True
        right = self.findStr(board, word, i, j + 1, index + 1, posSet.copy())
        return right


class Test(unittest.TestCase):
    board1 = [
        ["A","B","C","E"],
        ["S","F","C","S"],
        ["A","D","E","E"]
    ]
    board2 = [
        ["A","B","C","E"],
        ["S","F","E","S"],
        ["A","D","E","E"]
    ]
    board3 = [
        ["b","a","a","b","a","b"],
        ["a","b","a","a","a","a"],
        ["a","b","a","a","a","b"],
        ["a","b","a","b","b","a"],
        ["a","a","b","b","a","b"],
        ["a","a","b","b","b","a"],
        ["a","a","b","a","a","b"]
    ]
    word1 = "ABCCED"
    word2 = "ABCESEEEFS"
    word3 = "abaabbbaaaaababbbaaaaabbbaab"

    def test1(self):
        sol = Solution()
        self.assertTrue(sol.exist(self.board1, self.word1))

    def test2(self):
        sol = Solution()
        self.assertTrue(sol.exist(self.board2, self.word2))

    def test3(self):
        sol = Solution()
        self.assertTrue(sol.exist(self.board3, self.word3))


if __name__ == '__main__':
    unittest.main()