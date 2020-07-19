#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        unordered_map<char, vector<pair<int,int>>> posMap;
        for(int i = 0; i < s.size(); i++){
            for(int j = i + 1; j < s.size(); j++){
                if(!isPalind(i, j, s))
                    continue;
                if(posMap.find(s[i]) == posMap.end())
                    posMap.insert({s[i], vector<pair<int, int>>()});
                posMap[s[i]].push_back(pair<int, int>(i, j));
            }
        }

        vector<pair<int, vector<string>>> partitions = {pair<int, vector<string>>(0,vector<string>())};
        for(int i = 0; i < s.size(); i++){
            for(pair<int, vector<string>>& partition: partitions){
                if(partition.first != i)
                    continue;
                for(pair<int, int>& palindPair: posMap[s[i]]){
                    if(palindPair.first != i)
                        continue;
                    auto newPartition = pair<int, vector<string>>(partition);
                    int start = palindPair.first;
                    int end = palindPair.second;
                    newPartition.first = end + 1;
                    newPartition.second.push_back(s.substr(start, end - start + 1));
                    partitions.push_back(newPartition);
                }
                partition.first++;
                partition.second.push_back(s.substr(i, 1));
            }
        }
        vector<vector<string>> ans;
        for(auto& partition: partitions){
            ans.push_back(partition.second);
        }
        return ans;
    }

private:
    bool isPalind(int start, int end, string s){
        int left = start;
        int right = end;
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

};

int main(void){
    string s = "ababb";
    Solution sol;
    vector<vector<string>> ans = sol.partition(s);
    for(auto& partitions: ans){
        for(string partition: partitions){
            cout << partition << " ";
        }
        cout << endl;
    }
    return 0;
}