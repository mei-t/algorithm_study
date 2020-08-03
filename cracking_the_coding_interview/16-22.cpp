#include <iostream>
#include <vector>
using namespace std;

class LangtonsAnt{
public:
    LangtonsAnt(): matrix(vector<vector<bool>>(INT_MAX, vector<bool>(INT_MAX, true))), 
        pos(pair<int, int>(0, 0)), dir(0) {}
    
    void printMoves(int k){
        for(int i = 0; i < k; i++){
            bool isWhite = matrix[pos.first][pos.second];
            matrix[pos.first][pos.second] = !isWhite;
            rotate(isWhite);
            next();
        }
    }

private:
    vector<vector<bool>> matrix;
    pair<int, int> pos;
    int dir;
    
    void rotate(bool clockwise){
        dir += clockwise ? 1 : 3;
        dir %= 4;
    }

    void next(){
        switch(dir){
            case 0:
                pos.first++;
                break;
            case 1:
                pos.second--;
                break;
            case 2:
                pos.first--;
                break;
            case 3:
                pos.second++;
        }
    }
};

int main(void){
    LangtonsAnt la;
    la.printMoves(7);
    return 0;
}