#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<pair<int, int>> findSum(const vector<int>& nums, int target){
    unordered_set<int> numSet;
    unordered_set<int> done;
    vector<pair<int, int>> res;
    for(int num: nums){
        if(numSet.count(num) == 0){
            numSet.insert({target - num});
            continue;
        }
        res.push_back(pair<int, int>(num, target - num));
        numSet.erase(num);
    }
    return res;
}

int main(void){
    vector<int> input1 = {1, 2, 3, 4, 5};
    vector<pair<int, int>> res1 = findSum(input1, 5);
    for(auto numPair: res1){
        cout << numPair.first << " " << numPair.second << endl;
    }
    return 0;
}