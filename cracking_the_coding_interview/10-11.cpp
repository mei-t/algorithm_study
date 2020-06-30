#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> topAndBottom(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int mid = nums.size() / 2;
    vector<int> small(nums.begin(), nums.begin() + mid);
    vector<int> large(nums.begin() + mid, nums.end());
    for(int i = 0; i < nums.size(); i++){
        nums[i] = (i % 2 == 0 ? large[i/2] : small[i/2]);
    }
    return nums;
}

vector<int> topAndBottom2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++) {
        if(i % 2)
            swap(nums[i], nums[i - 1]);
    }
    return nums;
}

void output(vector<int> nums) {
    for(int num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main(void) {
    vector<int> nums1 = {5, 3, 1, 2, 3};
    topAndBottom(nums1);
    output(nums1);
    vector<int> nums2 = {5, 3, 1, 2, 3};
    topAndBottom2(nums2);
    output(nums2);
    return 0;
}