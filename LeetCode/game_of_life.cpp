#include <iostream>
#include <vector>
using namespace std;

class Solution_with_less_memory {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty())
            return;
        row_size = board.size();
        line_size = board[0].size();
        for(int i = 0; i < row_size; i++){
            for(int j = 0; j < line_size; j++){
                int live_count = countLiveCell(board, i, j);
                if(live_count == 3 && board[i][j] == 0)
                    board[i][j] = -1;
                if(live_count != 2 && live_count != 3 && board[i][j] == 1)
                    board[i][j] = 2;
            }
        }
        for(int i = 0; i < row_size; i++){
            for(int j = 0; j < line_size; j++){
                if(board[i][j] == 2)
                    board[i][j] = 0;
                if(board[i][j] == -1)
                    board[i][j] = 1;
            }
        }
    }

private:
    unsigned int row_size;
    unsigned int line_size;
    int countLiveCell(const vector<vector<int>>& board, int x, int y){
        int live_count = 0;
        for(int i = -1; i < 2; i++){
            if(x + i < 0 || x + i >= row_size)
                continue;
            for(int j = -1; j < 2; j++){
                if((i == 0 && j == 0) || y + j < 0 || y + j >= line_size)
                    continue;
                if(board[x + i][y + j] > 0){
                    live_count++;
                }
            }
        }
        return live_count;
    }
};

class Solution_standard {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy(board);
        if(board.empty())
            return;
        row_size = board.size();
        line_size = board[0].size();
        for(int i = 0; i < row_size; i++){
            for(int j = 0; j < line_size; j++){
                int live_count = countLiveCell(copy, i, j);
                switch(live_count){
                    case 2:
                        break;
                    case 3:
                        board[i][j] = 1;
                        break;
                    default:
                        board[i][j] = 0;
                }
            }
        }
    }

private:
    unsigned int row_size;
    unsigned int line_size;
    int countLiveCell(const vector<vector<int>>& board, int x, int y){
        int live_count = 0;
        for(int i = -1; i < 2; i++){
            if(x + i < 0 || x + i >= row_size)
                continue;
            for(int j = -1; j < 2; j++){
                if((i == 0 && j == 0) || y + j < 0 || y + j >= line_size)
                    continue;
                if(board[x + i][y + j]){
                    live_count++;
                }
            }
        }
        return live_count;
    }
};

int main(void){
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    Solution_with_less_memory sol;
    sol.gameOfLife(board);
    for(vector<int>& line: board){
        for(int num: line){
            cout << num << " ";
        }
        cout << endl;
    }
}