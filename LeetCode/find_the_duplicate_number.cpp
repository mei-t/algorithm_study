#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        int x1 = 0;
        int x2 = 0;
        while(1){
            x1 = nums[x1];
            x2 = nums[nums[x2]];
            if(x1 == x2)
                break;
        }
        x1 = 0;
        while(1){
            x1 = nums[x1];
            x2 = nums[x2];
            if(x1 == x2)
                return x1;
        }
        return -1; // Return -1 if the duplicate number does not find.
    }
};

// Simple solution with O(1) extra space.
class SimpleSolution {
public:
    int findDuplicate(const vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j])
                    return nums[i];
            }
        }
        return -1; // Return -1 if the duplicate number does not find.
    }
};

int main(void){
    Solution sol;
    vector<int> input1 = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(input1) << endl;
    SimpleSolution sSol;
    vector<int> input2 = {1, 3, 4, 2, 2};
    cout << sSol.findDuplicate(input2) << endl;
    return 0;
}