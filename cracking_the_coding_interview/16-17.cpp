#include <iostream>
#include <vector>
using namespace std;

int maxSum(const vector<int>& nums){
    int sum = 0;
    int max = INT_MIN;
    for(int num: nums){
        sum += num;
        if(max < sum)
            max = sum;
        if(sum < 0)
            sum = 0;
    }
    return max;
}

int main(void){
    vector<int> nums1 = {2, -8, 3, -2, 4, -10};
    vector<int> nums2 = {-2, -8, -3, -2, -4, -10};
    vector<int> nums3 = {2, 8, 3, 2, 4, 10};
    cout << maxSum(nums1) << endl;
    cout << maxSum(nums2) << endl;
    cout << maxSum(nums3) << endl;
    return 0;
}