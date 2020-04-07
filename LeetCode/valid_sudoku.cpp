#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            vector<bool> isVerticalAppeared(9, false);
            for(int j=0; j<9; j++){
                if(!isValid(board, i, j, isVerticalAppeared)){
                    return false;
                }
            }
            vector<bool> isHolizonalAppeared(9, false);
            for(int j=0; j<9; j++){
                if(!isValid(board, j, i, isHolizonalAppeared)){
                    return false;
                }
            }
            vector<bool> isBlockAppeared(9, false);
            for(int j=0; j<9; j++){
                if(!isValid(board, (i%3)*3 + j%3, (i/3)*3 + j/3, isBlockAppeared)){
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool isValid(vector<vector<char>>& board, int x, int y, vector<bool>& isAppeared){
        // cout << "x = " << x << ", y = " << y << endl;
        if(board[x][y] == '.'){
            return true;
        }
        int num = board[x][y] - '0';
        if(isAppeared[num]){
            // cout << "x = " << x << ", y = " << y << ", num = " << num << endl;
            return false;
        }
        isAppeared[num] = true;
        return true;
    }
};

int main(void){
    vector<vector<char>> input = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    cout << (sol.isValidSudoku(input) ? "true" : "false") << endl;
    return 0;
}