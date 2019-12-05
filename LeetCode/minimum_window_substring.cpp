#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
using namespace std;

// 1つだけテスト通らなかった(stack-overflow)
class Solution {
public:
    string minWindow(string s, string t) {
        size_t size = s.size();
        for(char c: t){
            if(dict.count(c)){
                dict.insert({c, 0});
                inWindow.insert({c, 0});
            }
            dict[c]++;
        }
        
        cout << s.size() << endl;
        cout << dict.size() << endl;
        for(int i=0; i<s.size(); i++){
            if(dict.count(s[i])){
                filtered.push_back(make_pair(s[i], i));
            }
        }
        cout << filtered.size() << endl;

        rightMove(0, 0, dict.size());
        string ans = "";
        if(range.second < INT_MAX){
            cout << "aaa" << endl;
            ans = s.substr(range.first, range.second);
        }
        return ans;
    }

    void rightMove(size_t left, size_t right, const size_t size){
        if(right >= filtered.size()){
            return;
        }

        char c = filtered[right].first;
        inWindow[c]++;
        if(dict[c] == inWindow[c]){
            count++;
        }
        if(count >= size){
            leftMove(left, right, size);
        }else{
            rightMove(left, ++right, size);
        }
    }

    void leftMove(size_t left, size_t right, const size_t size){
        if(left >= filtered.size()){
            return;
        }
        char c = filtered[left].first;
        if(dict[c] >= inWindow[c]){
            inWindow[c]--;
            count--;
            int len = filtered[right].second - filtered[left].second + 1;
            if(range.second > len){
                cout << filtered[left].second << ", " << len << endl;
                cout << "left = " << left << ", right = " << right << endl;
                range = make_pair(filtered[left].second, len);
            }
            rightMove(++left, ++right, size);
        }else{
            inWindow[c]--;
            leftMove(++left, right, size);
        }
    }

private:
    int count = 0;
    pair<int, int> range = make_pair(0, INT_MAX);
    unordered_map<char, int> dict;
    unordered_map<char, int> inWindow;
    vector<pair<char, int>> filtered;
};

int main(void){
    return 0;
}