#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

pair<string, int> split(string s, const unordered_set<string>& dict, unordered_map<int, pair<string, int>>* strMap){
    if(s.empty() || dict.find(s) != dict.end()){
        return make_pair(s, 0);
    }else if(strMap->find(s.size()) != strMap->end()){
        return (*strMap)[s.size()];
    }

    string result;
    int unrecognized = s.size() + 1;
    for(int i = 1; i < s.size(); i++){
        string subs = s.substr(0, i);
        auto p = split(s.substr(i), dict, strMap);
        int tmp = p.second + (dict.find(subs) != dict.end() ? 0 : i);
        if(tmp < unrecognized){
            result = subs + " " + p.first;
            unrecognized = tmp;
        }
    }
    strMap->insert({s.size(), make_pair(result, unrecognized)});
    return make_pair(result, unrecognized);
}

int main(void){
    return 0;
}