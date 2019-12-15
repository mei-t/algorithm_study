#include <iostream>
#include <vector>
using namespace std;

// 10分41秒

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(auto it = nums.begin(); it != nums.end(); ){
            if(*it < 1){
                nums.erase(it);
            }else{
                it++;
            }
        }

        sort(nums.begin(), nums.end());
        int i = 1;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != i){
                if(j == 0 || nums[j - 1] != nums[j]){
                    return i;
                }
            }else{
                i++;
            }
        }
        return i;
    }
};

int main(void){
    return 0;
}