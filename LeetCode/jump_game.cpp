#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int prev = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            int current = max(prev - 1, nums[i]);
            if(current == 0){
                return false;
            }
            prev = current;
        }
        return true;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] == 0){
                int continuousZeros = countContinuousZeros(nums, i);
                if(!canJump(nums, continuousZeros, &i)){
                    return false;
                }
            }
        }
        return true;
    }
private:
    int countContinuousZeros(vector<int>& nums, int n){
        int continuousZeros = 0;
        for(int i = n; i >= 0; i--){
            if(nums[i] != 0){
                return continuousZeros;
            }
            continuousZeros++;
        }
        return continuousZeros;
    }

    bool canJump(vector<int>& nums, int continuousZeros, int* n){
        *n = *n - continuousZeros;
        for(int i = *n; i >= 0; i--){
            if(nums[i] > continuousZeros + *n - i){
                *n = i;
                return true;
            }
        }
        return false;
    }
};

int main(void){
    Solution2 sol;
    vector<int> input1 = {3, 2, 1, 0, 4};
    vector<int> input2 = {0, 3, 1, 0, 4, 3, 2, 0, 1};
    // sol.canJump(input1);
    sol.canJump(input2);
    return 0;
}