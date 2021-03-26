# TLE
class Solution:
    def wordsTyping(self, sentence, rows, cols):
        lengthes = list(map(len, sentence))
        cur_row = 0
        cur_col = 0
        count = -1
        while cur_row < rows:
            count += 1
            for length in lengthes:
                if length > cols:
                    return 0
                if cols - cur_col < length:
                    cur_row += 1
                    cur_col = length + 1
                else:
                    cur_col += length + 1
                
        return count