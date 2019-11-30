#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<string, bool> memo;
        return isMatch(s, p, memo);
    }
    
    bool isMatch(string s, string p, unordered_map<string, bool>& memo) {
        if(p.empty()){
            return s.empty();
        }
        if(memo.count(s + " " + p)){
            return memo[s + " " + p];
        }
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        bool result;
        if(p.size() > 1 && p[1] == '*'){
            result = isMatch(s, p.substr(2), memo) || (firstMatch && isMatch(s.substr(1), p, memo));
        }else{
            result = firstMatch && isMatch(s.substr(1), p.substr(1), memo);
        }
        memo.insert({s + " " + p, result});
        return result;
    }
};

// 良くわからなかった
class Solution2 {
public:
    bool isMatch(string s, string p) {
        vector<bool> line(p.size()+1);
        vector<vector<bool>> dp(s.size()+1, line);
        dp[s.size()][p.size()] = true;
        for(int i=s.size(); i >= 0; i--){
            for(int j = p.size() - 1; j >= 0; j--){
                bool firstMatch = (i < s.size()) && (s[i] == p[j] || p[j] == '.');
                if(p.size() > j + 1 && p[j + 1] == '*'){
                    dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j]);
                }else{
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};

int main(void){
    return 0;
}