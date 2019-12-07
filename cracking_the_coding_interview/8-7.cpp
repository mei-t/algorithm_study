#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void permuWithoutDupli(vector<string>* ans, string preS, const string& input, unordered_set<char>* charSet){
    if(charSet->size() >= input.size()){
        return;
    }
    for(int i=0; i<input.size(); i++){
        if(charSet->find(input[i]) == charSet->end()){
            string newString = preS + input[i];
            ans->push_back(newString);
            unordered_set<char> newCharSet(*charSet);
            newCharSet.insert(input[i]);
            permuWithoutDupli(ans, newString, input, &newCharSet);
        }
    }
}

vector<string> permuWithoutDupli(const string& input){
    vector<string> ans;
    unordered_set<char> charSet;
    permuWithoutDupli(&ans, "", input, &charSet);
    return ans;
}

int main(void){
    string input = "abc";
    vector<string> ans = permuWithoutDupli(input);
    for(string s: ans){
        cout << s << endl;
    }
    return 0;
}