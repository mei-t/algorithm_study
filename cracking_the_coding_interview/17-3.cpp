#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void randSubSet(vector<int>& nums, size_t newSize, size_t i){
    if(i == nums.size()){
        nums.resize(newSize);
        return;
    }

    size_t j = rand() / (RAND_MAX + 1u) / (i + 1);
    if(j < newSize){
        swap(nums[i], nums[j]);
    }
    randSubSet(nums, newSize, i + 1);
}

void randSubSet(vector<int>& nums, size_t newSize){
    randSubSet(nums, newSize, newSize + 1);
    return;
}

vector<int> randSubSetWithForRoop(vector<int>& nums, size_t newSize){
    auto first = nums.begin();
    auto last = nums.begin() + newSize;
    vector<int> subSet(first, last);
    for(int i = newSize; i < nums.size(); i++){
        size_t j = rand() / (RAND_MAX + 1u) / (i + 1);
        if(j < newSize){
            subSet[j] = nums[i];
        }
    }
    return subSet;
}

int main(void){
    vector<int> nums1 = {345, 6, 312, 43, 56, 1, 36, 638, 49, 50};
    randSubSet(nums1, 5);
    for (int num: nums1){
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {345, 6, 312, 43, 56, 1, 36, 638, 49, 50};
    vector<int> res = randSubSetWithForRoop(nums2, 5);
    for (int num: res){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}