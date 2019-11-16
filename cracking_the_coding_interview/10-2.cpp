#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isAnaglam(string s1, string s2){
    unordered_set<char> charInS1;
    for(char c : s1){
        charInS1.insert(c);
    }
    for(char c : s2){
        if(charInS1.find(c) == charInS1.end()){
            return false;
        }
    }
    return true;
}

vector<string> anaglamGroup(const vector<string>& sList){
    vector<string> ans;

    unordered_map<int, vector<string> > sMap;
    vector<int> sizeList;
    // バケツソート
    // TC: O(sList.size())
    // SC: O(sList.size() * ave(s.size()))
    for(string s: sList) {
        if(sMap.find(s.size()) == sMap.end()){
            sMap.insert({s.size(), vector<string>()});
            sizeList.push_back(s.size());
        }
        sMap[s.size()].push_back(s);
    }

    unordered_set<string> blackList;
    for(int size: sizeList){
        const vector<string> &stringList = sMap[size];
        for(int i = 0; i < sMap[size].size(); i++){
            const string &s1 = stringList[i];
            if(blackList.find(s1) == blackList.end()) {
                ans.push_back(s1);
                for(int j = i + 1; j < stringList.size(); j++){
                    const string s2 = stringList[j];
                    if(blackList.find(s2) == blackList.end() && isAnaglam(s1, s2)) {
                        ans.push_back(s2);
                        blackList.insert(s2);
                    }
                }
            }
        }
    }

    return ans;
}

int main(void){
    return 0;
}