#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void parenthesisArrange(pair<int, int>& p, string s, vector<string>& ans){
    if(p.second == 0){
        ans.push_back(s);
        return;
    }
    if(p.first > 0){
        pair<int, int> left(p.first-1, p.second);
        parenthesisArrange(left, s + "(", ans);
    }
    if(p.first != p.second){
        pair<int, int> right(p.first, p.second-1);
        parenthesisArrange(right, s + ")", ans);
    }
}

vector<string> parenthesisArrange(int n){
    pair<int, int> p(n, n);
    vector<string> ans;
    parenthesisArrange(p, "", ans);
    return ans;
}

int main(void){
    vector<string> ans = parenthesisArrange(3);
    for(string& s: ans){
        cout << s << endl;
    }
    return 0;
}