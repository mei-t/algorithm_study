#include <iostream>
#include <vector>
using namespace std;

int findStart(const vector<int>& nums, int left, int right){
    int mid = (left + right) / 2;

    if(left + 1 == right){
        if(nums[left] > nums[right]){
            return right;
        }else{
            return 0;
        }
    }

    if(nums[left] == nums[mid]){
        int result = findStart(nums, left, mid);
        if(result > 0){
            return result;
        }else{
            return findStart(nums, mid, right);
        }
    }

    if(nums[mid] > nums[left]){
        return findStart(nums, mid, right);
    }else{
        return findStart(nums, left, mid);
    }
}

int findNum(const vector<int>& nums, int target, int left, int right){
    int mid = (left + right) / 2;

    if(left > right){
        return -1;
    }
    if(target == nums[mid]){
        return mid;
    }

    if(nums[mid] > target){
        return findNum(nums, target, left, mid - 1);
    }else{
        return findNum(nums, target, mid + 1, right);
    }
    return -1;
}

int findNum(const vector<int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;
    int start = findStart(nums, left, right);
    cout << "start = " << start << endl;
    int ans = -1;
    if(nums[0] <= target){
        ans = findNum(nums, target, left, start - 1);
    }else{
        ans = findNum(nums, target, start, right);
    }
    return ans;
}

int main(void){
    vector<int> nums1 = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    vector<int> nums2 = {2, 2, 2, 3, 4, 2};
    cout << findNum(nums1, 5) << endl;
    cout << findNum(nums2, 4) << endl;
    return 0;
}