#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<string> anaglamGroup(const vector<string>& sList){
    vector<string> ans;

    unordered_map<int, vector<pair<string, string>> > sMap;
    vector<int> sizeList;
    // バケツソート
    // TC: O(sList.size())
    // SC: O(sList.size() * ave(s.size()))
    for(const string& s: sList) {
        if(sMap.find(s.size()) == sMap.end()){
            sMap.insert({s.size(), vector<pair<string, string>>()});
            sizeList.push_back(s.size());
        }
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        sMap[s.size()].push_back(make_pair(s, sorted));
    }

    // unordered_set<string> blackList;
    // for(int size: sizeList){
    //     const vector<pair<string, string>> &stringList = sMap[size];
    //     for(int i = 0; i < stringList.size(); i++){
    //         const pair<string, string> &s1_pair = stringList[i];
    //         if(blackList.find(s1_pair.first) == blackList.end()) {
    //             ans.push_back(s1_pair.first);
    //             for(int j = i + 1; j < stringList.size(); j++){
    //                 const pair<string, string> s2_pair = stringList[j];
    //                 if(blackList.find(s2_pair.first) == blackList.end() && s1_pair.second == s2_pair.second) {
    //                     ans.push_back(s2_pair.first);
    //                     blackList.insert(s2_pair.first);
    //                 }
    //             }
    //         }
    //     }
    // }

    // iterator version
    for (auto itr = sMap.begin(); itr != sMap.end(); itr++){
        auto &stringList = itr->second;
        for(auto itr2 = stringList.begin(); itr2 != stringList.end(); itr2++){
            auto &s1_pair = *itr2;
            ans.push_back(s1_pair.first);
            for(auto itr3 = itr2 + 1; itr3 != stringList.end();){
                auto &s2_pair = *itr3;
                if(s1_pair.second == s2_pair.second){
                    ans.push_back(s2_pair.first);
                    itr3 = stringList.erase(itr3);
                }else{
                    itr3++;
                }
            }
        }
    }

    return ans;
}

int main(void){
    vector<string> v = {"aac", "kdnsr", "dkx", "cac", "aca"};
    vector<string> ans = anaglamGroup(v);
    for(string s: ans){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}