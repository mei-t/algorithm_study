#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void topAndBottom(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int mid = nums.size() / 2;
    vector<int> small(nums.begin(), nums.begin() + mid);
    vector<int> large(nums.begin() + mid, nums.end());
    for(int i = 0; i < nums.size(); i++){
        nums[i] = (i % 2 == 0 ? large[i/2] : small[i/2]);
    }
    return;
}

void topAndBottom2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++) {
        if(i % 2)
            swap(nums[i], nums[i - 1]);
    }
    return;
}

void topAndBottom3(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i += 2) {
        int max = i;
        if(i != 0)
            max = (nums[i] > nums[i - 1] ? i : i - 1);
        if(i != nums.size() - 1)
            max = (nums[max] > nums[i + 1] ? max : i + 1);
        if(i != max)
            swap(nums[i], nums[max]);
    }
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
    vector<int> nums3 = {5, 3, 1, 2, 3};
    topAndBottom3(nums3);
    output(nums3);
    return 0;
}