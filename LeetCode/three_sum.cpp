#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> numsWithoutDupli;
        numMap.insert({0, 0});
        for(int num: nums){
            if(numMap.find(num) == numMap.end()){
                numMap.insert({num, 0});
                numsWithoutDupli.push_back(num);
            }
            numMap[num]++;
        }
        if(numMap[0] > 2){
            vector<int> newList = {0, 0, 0};
            ans.push_back(newList);
        }
        if(numMap[0] > 0){
            for(int num: numsWithoutDupli){
                if(num >= 0){
                    break;
                }
                if(numMap.find(-1 * num) != numMap.end()){
                    vector<int> newList = {0, num, -1 * num};
                    ans.push_back(newList);
                }
            }
        }
        // numMap.erase(0);
        for(int i = 0; i < numsWithoutDupli.size(); i++){
            int num = numsWithoutDupli[i];
            if(listMap.find(num) != listMap.end()){
                cout << "a) i = " << i << endl;
                pushAns(num, listMap[num], ans);
            }
            for(int j = 0; j < i; j++){
                pushListMap(numsWithoutDupli[j], num);
            }
            if(numMap[num] > 1){
                int tmp = num * (-1) * 2;
                if(num > 0 && numMap.find(tmp) != numMap.end()){
                    vector<int> list = {num, num};
                    vector<vector<int>> lists =  {list};
                    cout << "b) i = " << i << endl;
                    pushAns(tmp, lists, ans);
                }
                pushListMap(num, num);
            }
        }
        // for(int i = 0; i < nums.size(); i++){
        //     if(numMap.find(nums[i]) != numMap.end()){
        //         pushAns(ans, numMap[nums[i]], nums[i]);
        //     }
        //     if(numSet.find(nums[i]) != numSet.end()){
        //         pushNumMap(nums[i], nums[i]);
        //         continue;
        //     }
        //     for(auto itr = numSet.begin(); itr != numSet.end(); itr++){
        //         pushNumMap(nums[i], *itr);
        //     }
        //     numSet.insert(nums[i]);
        // }
        return ans;
    }

private:
    // unordered_set<int> numSet;
    // unordered_map<int, vector<vector<int>>> numMap;
    unordered_map<int, int> numMap;
    unordered_map<int, vector<vector<int>>> listMap;
    void pushListMap(int num1, int num2){
        int key = -1 * (num1 + num2);
        if(listMap.find(key) != listMap.end()){
            listMap.insert({key, vector<vector<int>>()});
        }
        vector<int> pair = {num1, num2};
        listMap[key].push_back(pair);
    }

    void pushAns(int num, vector<vector<int>>& numLists, vector<vector<int>>& ans){
        for(vector<int>& list: numLists){
            list.push_back(num);
            ans.push_back(list);
        }
    }
    // void pushAns(vector<vector<int>>& ans, vector<vector<int>>& list, int num){
    //     for(vector<int>& numPair: numMap[num]){
    //         if(numPair.size() > 2){
    //             continue;
    //         }
    //         numPair.push_back(num);
    //         ans.push_back(numPair);
    //     }
    // }
    // void pushNumMap(int num1, int num2){
    //     int key = (-1) * (num1 + num2);
    //     if(numMap.find(key) == numMap.end()){
    //         numMap.insert({key, vector<vector<int>>()});
    //     }
    //     vector<int> newList = {num1, num2};
    //     numMap[key].push_back(newList);
    // }
};

int main(void){
    return 0;
}