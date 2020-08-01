#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Assume all the numbers are positive.
// Return -1 if the number doesn't find.
// TC: O(NlogN) where N is the size of input array.
// SC: O(1)
pair<int, int> swapSum1(vector<int>& nums1, vector<int>& nums2){
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

// TC: O(N) where N is the size of input array.
// SC: O(N) where N is the size of input array.
pair<int, int> swapSum2(vector<int>& nums1, vector<int>& nums2){
    int sum1 = 0, sum2 = 0;
    for(int num: nums1)
        sum1 += num;
    for(int num: nums2)
        sum2 += num;

    int diff = sum1 - sum2;
    if(diff % 2)
        return pair<int, int>(-1, -1);
    unordered_map<int, int> numMap;
    for(int num : nums1){
        numMap.insert({num - diff/2, num});
    }
    for(int num : nums2){
        if(numMap.count(num) > 0)
            return pair<int, int>(numMap[num], num);
    }
    return pair<int, int>(-1, -1);
}
int main(void){
    vector<int> nums1 = {4, 1, 2, 1, 1, 2};
    vector<int> nums2 = {3, 6, 3, 3};
    pair<int, int> res1 = swapSum1(nums1, nums2);
    pair<int, int> res2 = swapSum1(nums2, nums1);
    pair<int, int> res3 = swapSum2(nums1, nums2);
    pair<int, int> res4 = swapSum2(nums2, nums1);
    cout << res1.first << " " << res1.second << endl;
    cout << res2.first << " " << res2.second << endl;
    cout << res3.first << " " << res3.second << endl;
    cout << res4.first << " " << res4.second << endl;
    return 0;
}