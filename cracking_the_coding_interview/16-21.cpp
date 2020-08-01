#include <iostream>
#include <vector>
using namespace std;

// Assume all the numbers are positive.
pair<int, int> swapSum(vector<int>& nums1, vector<int>& nums2){
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int sum1 = 0, sum2 = 0;
    for(int num: nums1)
        sum1 += num;
    for(int num: nums2)
        sum2 += num;

    int diff = sum1 > sum2 ? sum1 - sum2 : sum2 - sum1;
    if(diff % 2)
        return pair<int, int>(-1, -1);
    bool leftLarge = sum1 > sum2;
    vector<int>& larges = leftLarge ? nums1 : nums2;
    vector<int>& smalls = leftLarge ? nums2 : nums1;
    int largeInd = 0, smallInd = 0;
    while(largeInd < larges.size() && smallInd < smalls.size()){
        int large = larges[largeInd];
        int small = smalls[smallInd];
        if(large - small == diff / 2){
            return leftLarge ? pair<int, int>(large, small) : pair<int, int>(small, large);
        } else if(large - small < diff / 2){
            large++;
        } else {
            small++;
        }
    }
    return pair<int, int>(-1, -1);
}

int main(void){
    vector<int> nums1 = {4, 1, 2, 1, 1, 2};
    vector<int> nums2 = {3, 6, 3, 3};
    pair<int, int> res = swapSum(nums1, nums2);
    cout << res.first << " " << res.second << endl;
    return 0;
}