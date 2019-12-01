#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedian(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1);
    }
    
    double findMedian(const vector<int>& nums1, const vector<int>& nums2, int left1, int right1, int left2, int right2){
        cout << left1 << " "  << right1 << " " << left2 << " " << right2 << endl;
        if(left1 >= right1 && left2 >= right2){
            if((nums1.size() + nums2.size()) % 2){
                return ((double) nums1[left1] + (double) nums2[left2]) / 2;
            }
        }

        int mid1 = (left1 + right1) / 2;
        int mid2 = (left2 + right2) / 2;
        if(nums1[mid1] == nums2[mid2]){
            return (double) nums1[mid1];
        }

        if(nums1[mid1] > nums2[mid2]){
            int diff;
            if(left2 + right1 - mid1 <= right2){
                diff = right1 - mid1;
            }else{
                diff = mid2 - left2;
            }
            return findMedian(nums1, nums2, left1, right1 - diff, left2 + diff, right2);
        }
        
        int diff;
        if(left1 + right2 - mid2 <= right1){
            diff = right2 - mid2;
        }else{
            diff = mid1 - left1;
        }
        return findMedian(nums1, nums2, left1 + diff, right1, left2, right2 - diff);
    }
};

int main(void){
    return 0;
}