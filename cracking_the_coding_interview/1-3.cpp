#include <iostream>
using namespace std;

string urlify(const string& s){
    string ans;
    for(char c: s){
        if(c == ' '){
            ans += "%20";
        }else{
            ans += c;
        }
    }
    return ans;
}

int main(void){
    return 0;
}