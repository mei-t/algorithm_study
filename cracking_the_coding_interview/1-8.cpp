#include <iostream>
#include <vector>
#include <set>
using namespace std;

void setZero(vector<vector<int>>* matrix){
    if(matrix->empty()){
        return;
    }
    size_t row = matrix->size();
    size_t colum = (*matrix)[0].size();
    set<pair<int, int>> zeroPlace;
    for(int i=0; i<row; i++){
        for(int j=0; j<colum; j++){
            if((*matrix)[i][j] == 0){
                zeroPlace.insert(make_pair(i, j));
            }
        }
    }

    for(auto itr = zeroPlace.begin(); itr != zeroPlace.end(); itr++){
        for(int i=0; i<row; i++){
            (*matrix)[i][itr->second] = 0;
        }
        for(int i=0; i<colum; i++){
            (*matrix)[itr->first][i] = 0;
        }
    }

    return;
}

int main(void){
    vector<vector<int>> matrix = {
        {1, 0, 5, 3, 4},
        {4, 98, 8, 8, 5},
        {7, 0, 82, 0, 2},
        {5, 75, 7, 25, 1}
    };
    setZero(&matrix);
    for(const vector<int>& row: matrix){
        for(int num : row){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}