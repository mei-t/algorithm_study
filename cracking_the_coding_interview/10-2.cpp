#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

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
        for(int i = 0; i < sMap[size].size(); i++){
            string s1 = sMap[size][i];
            if(blackList.find(s1) == blackList.end()) {
                ans.push_back(s1);
                for(int j = i + 1; j < sMap[size].size(); j++){
                    string s2 = sMap[size][j];
                    if(blackList.find(s2) == blackList.end()) {
                        for(int k = 0; k < size; k++) {
                            if( s1[k] != s2[k]) {
                                break;
                            }
                            if(k == size - 1) {
                                ans.push_back(s2);
                                blackList.insert(s2);
                            }
                        }
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