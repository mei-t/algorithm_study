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

// おそらくBigO的な考え方的にも実際にも最適解の１つ
// TC: O(N) where N is the size of input.
class Solution4 {
public:
    int longestConsecutive(vector<int>& nums){
        unordered_map<int, pair<int, int>> numMap;
        int maxLen = 0;
        for(int num : nums){
            if(numMap.find(num) != numMap.end()){
                continue;
            }
            int tmp = 1;
            int min = num;
            int max = num;
            auto it = numMap.find(num - 1);
            if(it != numMap.end()){
                min = it->second.first;
                tmp += it->second.second - min + 1;
            }
            it = numMap.find(num + 1);
            if(it != numMap.end()){
                max = it->second.second;
                tmp += max - it->second.first + 1;
            }
            // これなくてもいける
            // if(min == num || max == num){
            //     numMap.insert({num, make_pair(min, max)});
            // }
            if(!(min == num && max == num)){
                numMap[num] = make_pair(min, max);
            }
            numMap[min] = make_pair(min, max);
            numMap[max] = make_pair(min, max);
            if(tmp > maxLen){
                maxLen = tmp;
            }
        }
        return maxLen;
    };
};