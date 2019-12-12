#include <iostream>
#include <vector>
#include <set>
using namespace std;

void setZeros(vector<vector<int>>* matrix){
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

void setRowZeros2(vector<vector<int>>* nums, size_t row){
    for(int i = 0; i < (*nums)[0].size(); i++){
        (*nums)[row][i] = 0;
    }
}

void setColumZeros2(vector<vector<int>>* nums, size_t colum){
    for(int i = 0; i < (*nums)[0].size(); i++){
        (*nums)[i][colum] = 0;
    }
}

void setZeros2(vector<vector<int>>* nums){
    if(nums->empty()){
        return;
    }
    bool isRowZero = false;
    bool isColumZero = false;
    size_t row = nums->size();
    size_t colum = (*nums)[0].size();

    for(int i = 0; i < colum; i++){
        if((*nums)[0][i] == 0){
            isRowZero = true;
            break;
        }
    }
    for(int i = 0; i < row; i++){
        if((*nums)[i][0] == 0){
            isColumZero = true;
            break;
        }
    }
    for(int i = 1; i< row; i++){
        for(int j = 1; j<colum; j++){
            if((*nums)[i][j] == 0){
                (*nums)[i][0] = 0;
                (*nums)[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < colum; i++){
        if((*nums)[0][i] == 0){
            setColumZeros2(nums, i);
        }
    }
    for(int i = 1; i < row; i++){
        if((*nums)[i][0] == 0){
            setRowZeros2(nums, i);
        }
    }
    if(isRowZero){
        setRowZeros2(nums, 0);
    }
    if(isColumZero){
        setColumZeros2(nums, 0);
    }
    return;
}

int main(void){
    vector<vector<int>> matrix1 = {
        {1, 0, 5, 3, 4},
        {4, 98, 8, 8, 5},
        {7, 0, 82, 0, 2},
        {5, 75, 7, 25, 1}
    };
    vector<vector<int>> matrix2 = matrix1;
    setZeros(&matrix1);
    for(const vector<int>& row: matrix1){
        for(int num : row){
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
    setZeros2(&matrix2);
    for(const vector<int>& row: matrix2){
        for(int num : row){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}