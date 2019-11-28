#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>>& v){
    for(const vector<int>& line: v){
        for(int num: line){
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate(vector<vector<int>>& matrix){
    size_t size = matrix.size();
    for(int i=0; i < size / 2; i++){
        for(int j=0; j < size / 2; j++){
            swap(matrix[i][j], matrix[size-j-1][i]);
            swap(matrix[size-j-1][i], matrix[size-i-1][size-j-1]);
            swap(matrix[size-i-1][size-j-1], matrix[j][size-i-1]);
        }
    }
    if(size % 2){
        int mid = size / 2;
        for(int i=0; i < size/2; i++){
            swap(matrix[i][mid], matrix[mid][i]);
            swap(matrix[mid][i], matrix[size-i-1][mid]);
            swap(matrix[size-i-1][mid], matrix[mid][size-i-1]);
        }
    }
    return;
}

int main(void){
    vector<vector<int>> v1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    print(v1);
    rotate(v1);
    print(v1);
    vector<vector<int>> v2;
    rotate(v2);
    print(v2);
    vector<vector<int>> v3 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    print(v3);
    rotate(v3);
    print(v3);
    return 0;
}