#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) : nums(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        mt19937 gen(rd());
        vector<int> res(nums);
        for(int i = 0; i < res.size(); i++) {
            uniform_int_distribution<> distrib(0, i);
            int tmp = distrib(gen);
            swap(res[i], res[tmp]);
        }
        return res;
    }
private:
    vector<int> nums;
    random_device rd;
};

void output(vector<int>& nums) {
    for(int num: nums) {
        cout << num << " ";
    }
    cout << endl;
    return;
}

int main(void) {
    vector<int> nums = {1, 2, 3};
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->shuffle();
    output(param_1);
    vector<int> param_2 = obj->reset();
    output(param_2);
    vector<int> param_3 = obj->shuffle();
    output(param_3);

    return 0;
}