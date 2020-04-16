#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted;
        for(string word: strs){
            sort(word.begin(), word.end());
            sorted.push_back(word);
        }
        unordered_map<string, int> wordMap;
        vector<vector<string>> ans;
        int index = 0;
        for(int i = 0; i < strs.size(); i++){
            if(wordMap.find(sorted[i]) == wordMap.end()){
                ans.push_back(vector<string>());
                wordMap.insert({sorted[i], index});
                index++;
            }
            ans[wordMap[sorted[i]]].push_back(strs[i]);
        }
        return ans;
    }
};

int main(void){
    return 0;
}