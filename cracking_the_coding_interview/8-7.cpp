#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void permuWithoutDupli(vector<string>* ans, string preS, string rest){
    if(rest.empty()){
        ans->push_back(preS);
        return;
    }
    for(int i=0; i<rest.size(); i++){
        string newString = preS + rest[i];
        string newRest = rest.substr(0, i) + rest.substr(i + 1);
        permuWithoutDupli(ans, newString, newRest);
    }
}

vector<string> permuWithoutDupli(const string& input){
    vector<string> ans;
    permuWithoutDupli(&ans, "", input);
    return ans;
}

void permuWithoutDupli2(vector<string>* ans, string preS, const string& input, size_t index){
    if(index == input.size()){
        ans->push_back(preS);
        return;
    }
    for(int i=0; i<preS.size() + 1; i++){
        string newString = preS.substr(0, i) + input[index] + preS.substr(i);
        permuWithoutDupli2(ans, newString, input, index + 1);
    }
}

vector<string> permuWithoutDupli2(const string& input){
    vector<string> ans;
    if(input.empty()){
        return ans;
    }
    string first;
    first += input[0];
    permuWithoutDupli2(&ans, first, input, 1);
    return ans;
}

int main(void){
    string input = "abc";
    vector<string> ans1 = permuWithoutDupli(input);
    for(string s: ans1){
        cout << s << endl;
    }
    cout << endl;
    vector<string> ans2 = permuWithoutDupli2(input);
    for(string s: ans2){
        cout << s << endl;
    }
    return 0;
}