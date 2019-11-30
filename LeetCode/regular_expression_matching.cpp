#include <iostream>
#include <unordered_map>
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

int main(void){
    return 0;
}