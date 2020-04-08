#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        list<int> input(nums.begin(), nums.end());
        auto it = input.begin();
        for(int i=0; i < input.size(); i++){
            if(*it == 0){
                it = input.erase(it);
                input.push_front(0);
            }else if(*it == 1){
                it++;
            }else{
                it = input.erase(it);
                input.push_back(2);
            }
        }
        it = input.begin();
        for(int i=0; i<nums.size(); i++, it++){
            nums[i] = *it;
        }
        output(nums);
    }
private:
    void output(vector<int> nums){
        for(int num: nums){
            cout << num << " ";
        }
        cout << endl;
    }
};

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

int main(void){
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution sol;
    sol.sortColors(nums);
    return 0;
}