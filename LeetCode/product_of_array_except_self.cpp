#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int infProd = 1;
        int zeroCount = 0;
        for(int num: nums){
            if(num != 0){
                infProd *= num;
            }else{
                zeroCount++;
                if(zeroCount > 1){
                    return vector<int>(nums.size(), 0);
                }
            }
        }
        vector<int> ans;
        if(zeroCount == 1){
            for(int num: nums){
                num == 0 ? ans.push_back(infProd) : ans.push_back(0);
            }
            return ans;
        }
        for(int num: nums){
            ans.push_back(infProd / num);
        }
        return ans;
    }
};

int main(void){
    Solution sol;
    vector<int> nums = {1, 0};
    vector<int> ans = sol.productExceptSelf(nums);
    for(int num: ans){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}