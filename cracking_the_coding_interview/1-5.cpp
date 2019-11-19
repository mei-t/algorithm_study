#include <iostream>
#include <cmath>
using namespace std;

bool canChangeOnece(string s1, string s2){
    if(abs((int)s1.size() - (int)s2.size()) > 1){
        return false;
    }
    string shortString = s1.size() < s2.size() ? s1 : s2;
    string longString = s1.size() < s2.size() ? s2 : s1;
    int index1 = 0;
    int index2 = 0;
    bool isDiff = false;
    while(index1 < shortString.size() && index2 < longString.size()){
        if(shortString[index1] != longString[index2]){
            if(isDiff){
                return false;
            }
            isDiff = true;
            if(shortString.size() == longString.size()){
                index1++;
            }
        }else{
            index1++;
        }
        index2++;
    }
    return true;
}

int main(void){
    cout << canChangeOnece("pale", "bale") << endl;
    cout << canChangeOnece("pale", "bake") << endl;
    return 0;
}