#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mountainCave(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int mid = nums.size() / 2;
    vector<int> small(nums.begin(), nums.begin() + mid);
    vector<int> large(nums.begin() + mid, nums.end());
    for(int i = 0; i < nums.size(); i++){
        nums[i] = (i % 2 == 0 ? large[i/2] : small[i/2]);
    }
    return nums;
}

int main(void) {
    vector<int> nums = {5, 3, 1, 2, 3};
    mountainCave(nums);
    for(int num: nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}