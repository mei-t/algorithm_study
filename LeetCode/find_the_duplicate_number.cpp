#include <iostream>
#include <vector>
using namespace std;

class Solution {
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
    vector<int> input = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(input) << endl;
    return 0;
}