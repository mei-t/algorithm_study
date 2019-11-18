#include <iostream>
#include <vector>
using namespace std;

// 11分4秒

template <typename T>
// vectorのpush_back(value)はcopy of valueをvectorに入れるからsubSetは参照で良さそうだと思ったけど、だめだった
// 順番の問題
void createSubSet(vector<vector<T>>& ans, const vector<T>& allSet, vector<T> subSet, size_t index){
    if(index == allSet.size()){
        return;
    }

    createSubSet(ans, allSet, subSet, index + 1);
    subSet.push_back(allSet[index]);
    ans.push_back(subSet);
    createSubSet(ans, allSet, subSet, index + 1);
    return;
}

template <typename T>
vector<vector<T>> allSubSet(const vector<T>& allSet){
    vector<vector<T>> ans;
    vector<T> subSet;
    ans.push_back(subSet);
    createSubSet(ans, allSet, subSet, 0);
    return ans;
}


int main(void){
    vector<int> input = {0, 1, 2};
    vector<vector<int>> output = allSubSet(input);
    for(vector<int> subset : output){
        for (int num : subset){
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}