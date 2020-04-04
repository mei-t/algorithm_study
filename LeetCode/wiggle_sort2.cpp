#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        // output(sorted);
        for(int i=nums.size()-1, j=0, k=(nums.size() - 1)/2 + 1; i>=0; i--){
            nums[i] = sorted[(i%2 ? k++: j++)];
        }
        // output(nums);
    }
private:
    void output(vector<int>& input){
        for(int num: input){
            cout << num << " ";
        }
        cout << endl;
    }
};

int main(void){
    Solution sol;
    vector<int> input = {1, 1, 2, 1, 2, 2, 1};
    sol.wiggleSort(input);
    return 0;
}