#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#define SIZE 26

class Solution {
public:   
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> memo;
        return wordBreak(s, wordSet, memo);
    }
    
    bool wordBreak(string s, const unordered_set<string>& wordDict, unordered_map<string, bool>& memo){
        if(memo.count(s)){
            return memo[s];
        }
        if(wordDict.count(s)){
            return true;
        }
        
        for(int i=0; i<s.size(); i++){
            string word = s.substr(i);
            if(wordDict.count(word)){
                string res = s.substr(0, i);
                bool isResBreak = wordBreak(res, wordDict, memo);
                if(isResBreak){
                    memo.insert({s, true});
                    return true;
                }
            }
        }
        memo.insert({s, false});
        return false;
    }
};

int main(void){
    return 0;
}