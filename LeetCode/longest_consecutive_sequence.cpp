#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums);
private:
    int** init();
    void create(unordered_map<int, int**>* numMap, int num);
};

int Solution::longestConsecutive(vector<int>& nums) {
    unordered_map<int, int**> numMap;
    int maxLen = 0;
    for(int num : nums){
        create(&numMap, num);
        int** currentLen = numMap[num];
        cout << num << ", " << **currentLen << endl;
        if(**currentLen > 0){
            continue;
        }
        create(&numMap, num - 1);
        create(&numMap, num + 1);
        int** prevLen = numMap[num - 1];
        int** nextLen = numMap[num + 1];
        int len = **prevLen + 1 + **nextLen;
        if(**prevLen != 0){
            *prevLen = *currentLen;
        }
        if(**nextLen != 0){
            *nextLen = *currentLen;
        }
        **currentLen = len;
        if(len > maxLen){
            maxLen = len;
        }
        cout << num << " " << len << endl;
    }
    return maxLen;
}

int** Solution::init(){
    int len = 0;
    int* pLen = &len;
    int** pPLen = &pLen;
    return pPLen;
}

void Solution::create(unordered_map<int, int**>* numMap, int num){
    if(numMap->find(num) == numMap->end()){
        numMap->insert({num, init()});
    }
    return;
}

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int num : nums){
            numSet.insert(num);
        }
        
        int maxLen = 0;
        for(int num : nums){
            if(numSet.find(num) != numSet.end()){
                int currentNum = num;
                while(numSet.find(currentNum + 1) != numSet.end()){
                    currentNum += 1;
                }
                maxLen = max(maxLen, currentNum - num + 1);
            }
        }
        return maxLen;
    }
};

// sortする方法
// O(nlogn)
class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        int len = 1;
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            cout << prev << endl;
            if(prev + 1 == nums[i]){
                len++;
            }else if(prev != nums[i]){ 
                if(maxLen < len){
                    maxLen = len;
                }
                len = 1;
            }
            prev = nums[i];
        }
        if(len > maxLen){
            maxLen = len;
        }
        return maxLen;
    }
};