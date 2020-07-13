#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define GRID_SIZE 8

bool isValid(int row, int col, vector<pair<int, int>>& columns){
    for(int i = 0; i < row; i++) {
        if(col == columns[i].second || row - i == col - columns[i].second)
            return false;
    }
    return true;
}

vector<vector<pair<int, int>>> place_queen(int row, vector<pair<int, int>>& columns, vector<vector<pair<int, int>>>& results){
    if(row < GRID_SIZE) {
        for(int col = 0; col < GRID_SIZE; col++) {
            if(!isValid(row, col, columns))
                continue;
            columns.push_back(pair<int, int>(row, col));
            place_queen(row + 1, columns, results);
        } 
    } else {
        results.push_back(columns);
    }
    return results;
}
vector<vector<pair<int, int>>> place_queen(){
    vector<pair<int, int>> columns;
    vector<vector<pair<int, int>>> results;
    return place_queen(0, columns, results);
}

int main(void){
    return 0;
}