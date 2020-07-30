#include <iostream>
#include <vector>
using namespace std;

int maxSum(const vector<int>& nums){
    int sum = 0;
    int max = INT_MIN;
    for(int num: nums){
        sum += num;
        if(sum < 0)
            sum = 0;
        if(max < sum)
            max = sum;
    }
    return max;
}

int main(void){
    vector<int> nums = {2, -8, 3, -2, 4, -10};
    cout << maxSum(nums) << endl;
    return 0;
}