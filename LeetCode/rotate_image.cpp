#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i=0; i < size/2; i++){
            for(int j=0; j < size/2; j++){
                rotate_cycle(matrix, i, j);
            }
        }
        if(size%2){
            for(int i=0; i < size/2; i++){
                rotate_cycle(matrix, i, size/2);
            }
        }
        output(matrix);
    }
private:
    void rotate_cycle(vector<vector<int>>& matrix, int i, int j){
        int size = matrix.size();
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[size-1-j][i];
        matrix[size-1-j][i] = matrix[size-1-i][size-1-j];
        matrix[size-1-i][size-1-j] = matrix[j][size-1-i];
        matrix[j][size-1-i] = tmp;
    }
    void output(vector<vector<int>>& matrix){
        int size = matrix.size();
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(void){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution sol;
    sol.rotate(matrix);
    return 0;
}