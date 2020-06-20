#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 理解が不十分
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 0);
        vector<int> indicies(size, 0);
        iota(indicies.begin(), indicies.end(), 0);
        mergeCountSmaller(0, size, nums, indicies, result);
        return result;
    }

private:
    void mergeCountSmaller(int left, int right, vector<int>& nums, vector<int>& indicies, vector<int>& result){
        int count = right - left;
        if(count < 2)
            return;
        int step = count / 2;
        int mid = left + step;
        mergeCountSmaller(left, mid, nums, indicies, result);
        mergeCountSmaller(mid, right, nums, indicies, result);
        int ind1 = left;
        int ind2 = mid;
        int semicount = 0;
        vector<int> tmp;
        tmp.reserve(count);
        while(ind1 < mid || ind2 < right){
            if(ind2 == right || (ind1 < mid && nums[indicies[ind1]] <= nums[indicies[ind2]])){
                tmp.push_back(indicies[ind1]);
                result[indicies[ind1]] += semicount;
                ind1++;
            }else{
                tmp.push_back(indicies[ind2]);
                semicount++;
                ind2++;
            }
        }
        move(tmp.begin(), tmp.end(), indicies.begin() + left);
    } 
};

int main(void){
    vector<int> input = {5, 2, 6, 1};
    Solution sol;
    vector<int> ans = sol.countSmaller(input);
    for(int num: ans){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}