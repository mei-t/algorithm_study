#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void findString(const string& input, vector<string>* ans, size_t index, string preS){
    if(index == input.size()){
        ans->push_back(preS);
        return;
    }

    for(int  i = 0; i <= preS.size(); i++){
        string newS = preS.substr(0, i) + input[index] + preS.substr(i);
        findString(input, ans, index + 1, newS);
    }
}

vector<string> permuWithDupli(string input){
    unordered_set<char> charSet;
    for(int i = 0; i < input.size();){
        if(charSet.find(input[i]) != charSet.end()){
            input = input.substr(0, i) + input.substr(i + 1);
            continue;
        }
        charSet.insert(input[i]);
        i++;
    }

    vector<string> ans;
    findString(input, &ans, 0, "");
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