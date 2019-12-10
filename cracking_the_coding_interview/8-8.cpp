#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findString(const string& input, vector<string>* ans, size_t index, string preS, unordered_map<char, int>* charMap){
    if(index == input.size()){
        ans->push_back(preS);
        return;
    }

    for(auto it = charMap->begin(); it != charMap->end(); it++){
        if((*it).second > 0){
            string newS = preS + (*it).first;
            (*it).second--;
            findString(input, ans, index + 1, newS, charMap);
            (*it).second++;
        }
    }
}

vector<string> permuWithDupli(string input){
    unordered_map<char, int> charMap;
    for(int i = 0; i < input.size(); i++){
        if(charMap.find(input[i]) == charMap.end()){
            charMap.insert({input[i], 0});
        }
        charMap[input[i]]++;
    }

    vector<string> ans;
    findString(input, &ans, 0, "", &charMap);
    return ans;
}

int main(void){
    string input = "abcbbdc";
    vector<string> ans = permuWithDupli(input);
    for(string s : ans){
        cout << s << endl;
    }
    return 0;
}