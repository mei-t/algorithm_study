#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void randSubSet(vector<int>& nums, size_t newSize, size_t i){
    if(i == newSize){
        nums.resize(newSize);
        return;
    }

    size_t j = rand() / (RAND_MAX + 1u) / (i + 1);
    swap(nums[i], nums[j]);
    randSubSet(nums, newSize, i + 1);
}

void randSubSet(vector<int>& nums, size_t newSize){
    randSubSet(nums, newSize, 0);
    return;
}

int main(void){
    vector<int> nums = {345, 6, 312, 43, 56, 1, 36, 638, 49, 50};
    randSubSet(nums, 5);
    for (int num: nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}