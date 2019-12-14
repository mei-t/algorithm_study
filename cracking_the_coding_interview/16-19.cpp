#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 16分23秒

int computePondSize(vector<vector<int>>* land, int i, int j){
    if(i >= land->size() || j >= (*land)[0].size() || (*land)[i][j] != 0){
        return 0;
    }
    (*land)[i][j] = -1;
    return 1 + computePondSize(land, i+1, j-1) 
        + computePondSize(land, i+1, j) 
        + computePondSize(land, i+1, j+1) 
        + computePondSize(land, i, j+1);
}

unordered_set<int> computeAllPondSize(vector<vector<int>>* land){
    unordered_set<int> ans;
    for(int i = 0; i< land->size(); i++){
        for(int j = 0; j < (*land)[0].size(); j++){
            if((*land)[i][j] == 0){
                ans.insert(computePondSize(land, i, j));
            }
        }
    }
    return ans;
}

int main(void){
    vector<vector<int>> land = {
        {0, 2, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 1}
    };
    unordered_set<int> ans = computeAllPondSize(&land);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}