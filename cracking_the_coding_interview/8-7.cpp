#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void permuWithoutDupli(vector<string>* ans, string preS, string rest){
    if(rest.empty()){
        return;
    }
    for(int i=0; i<rest.size(); i++){
        string newString = preS + rest[i];
        ans->push_back(newString);
        string newRest = rest.substr(0, i) + rest.substr(i + 1);
        permuWithoutDupli(ans, newString, newRest);
    }
}

vector<string> permuWithoutDupli(const string& input){
    vector<string> ans;
    permuWithoutDupli(&ans, "", input);
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