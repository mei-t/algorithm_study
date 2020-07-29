#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> curs(1, {nums[nums.size() - 1]});
        for(int i = nums.size() - 2; i >= 0; i--){
            vector<vector<int>> prevs = curs;
            curs.clear();
            for(int j = 0; j < prevs.size(); j++){
                for(int k = 0; k <= prevs[0].size(); k++){
                    vector<int> prev = prevs[j];
                    prev.emplace(prev.begin() + k, nums[i]);
                    curs.push_back(prev);
                }
            }
        }
        return curs;
    }
};

int main(void){
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> res = sol.permute(nums);
    for(vector<int>& resNums: res){
        for(int num: resNums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}