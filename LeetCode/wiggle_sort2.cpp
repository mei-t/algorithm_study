#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        output(sorted);
        // for(int i=0; i<nums.size()/2; i++){
        //     nums[i*2] = sorted[i];
        //     nums[i*2 + 1] = sorted[nums.size()/2 + nums.size()%2 + i];
        // }
        for(int i=nums.size()-1, j=0, k=(nums.size() - 1)/2 + 1; i>=0; i--){
            nums[i] = sorted[(i%2 ? k++: j++)];
        }
        // if(nums.size()%2){
        //     nums[nums.size() - 1] = sorted[nums.size()/2];
        //     cout << "nums[" << nums.size() - 1 << "]" << endl;
        //     cout << "sorted[" << nums.size()/2 + 1 << "] = " << sorted[nums.size()/2 + 1] << endl;
        // }
        output(nums);
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