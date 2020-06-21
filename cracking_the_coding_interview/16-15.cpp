#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;
#define SIZE 4

enum Color {R, Y, G, B};

pair<int, int> masterMind(const string& correct, const string& expect){
    unordered_map<char, int> colMap;
    pair<int, int> ans = pair<int, int>(0, 0);
    string rest = "";
    for(int i = 0; i < SIZE; i++){
        if(correct[i] == expect[i]){
            ans.first++;
        }else{
            if(colMap.find(correct[i]) == colMap.end()){
                colMap.insert({correct[i], 0});
            }
            colMap[correct[i]]++;
            rest += expect[i];
        }
    }
    for(int i = 0; i < rest.size(); i++){
        if(colMap.find(rest[i]) == colMap.end())
            continue;
        ans.second++;
        if(colMap[rest[i]] < 2){
            colMap.erase(rest[i]);
        }else{
            colMap[rest[i]]--;
        }
    }
    return ans;
}

int main(void){
    string correct = "RGGB";
    string expect = "YRGB";
    pair<int, int> res = masterMind(correct, expect);
    cout << res.first << " " << res.second << endl;
    return 0;
}