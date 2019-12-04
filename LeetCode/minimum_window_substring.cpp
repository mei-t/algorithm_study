#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        size_t size = s.size();
        unordered_map<char, int> dict;
        for (char c: t){
            dict.insert({c, 0});
        }
        
        unordered_set<char> appeared;
        queue<pair<char, int>> charQueue;
        pair<int, int> ansRange;
        for(int i=0; i<s.size(); i++){
            if(dict.count(s[i])){
                if(!appeared.count(s[i])){
                    charQueue.push(make_pair(s[i], i));
                    appeared.insert(s[i]);
                }else{
                    dict[s[i]]++;
                    while(dict[charQueue.front().first]){
                        char c = charQueue.front().first;
                        charQueue.pop();
                        dict[c]--;
                        if(dict[c] == 0){
                            appeared.erase(c);
                        }
                    }
                }
                if(appeared.size() == dict.size() && ansRange.second > i - charQueue.front().second){
                    ansRange = make_pair(charQueue.front().second, i - charQueue.front().second);
                    char c = charQueue.front().first;
                    charQueue.pop();
                    dict[c]--;
                    if(dict[c] == 0){
                        appeared.erase(c);
                    }
                }
            }
        }
        cout << ansRange.first << " " << ansRange.second << endl;
        string ans = s.substr(ansRange.first, ansRange.second);
        return ans;
    }
};

int main(void){
    return 0;
}