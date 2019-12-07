#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<string, bool> matchMap;
        return isMatch(s, p, 0, 0, matchMap);
    }
    
    bool isMatch(string s, string p, size_t sIndex, size_t pIndex, unordered_map<string, bool>& matchMap){
        if(sIndex == s.size() && (pIndex == p.size() || (pIndex == p.size() - 1 && p[pIndex] == '*'))){
            return true;
        }else if(sIndex == s.size() || pIndex == p.size()){
            return false;
        }
        string index = to_string(sIndex) + " " + to_string(pIndex);
        if(matchMap.find(index) != matchMap.end()){
            return matchMap[index];
        }
        if(p[pIndex] != '*'){
            if(p[pIndex] == s[sIndex] || p[pIndex] == '?'){
                matchMap.insert({index, isMatch(s, p, sIndex + 1, pIndex + 1, matchMap)});
            }else{
                matchMap.insert({index, false});
            }
        }else{
            matchMap.insert({index, isMatch(s, p, sIndex + 1, pIndex, matchMap) || isMatch(s, p, sIndex, pIndex + 1, matchMap)});
        }
        return matchMap[index];
    }
};

int main(void){
    return 0;
}