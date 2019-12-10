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