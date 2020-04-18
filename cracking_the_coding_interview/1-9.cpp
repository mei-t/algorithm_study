#include <iostream>
using namespace std;

bool isSubstring(string& s1, string& s2){
    string longS = s1.size() > s2.size() ? s1 : s2;
    string shortS = s1.size() > s2.size() ? s2 : s1;
    for(int i = 0; i <= longS.size() - shortS.size(); i++){
        if(longS[i] != shortS[0]){
            continue;
        }
        for(int j = 0; j < shortS.size(); j++){
            if(longS[i + j] != shortS[j]){
                break;
            }
            if(j == shortS.size() - 1){
                return true;
            }
        }
    }
    return false;
}

bool isRotation(string& s1, string& s2){
    if(s1.size() != s2.size()){
        return false;
    }
    string doubleS1 = s1 + s1;
    return isSubstring(doubleS1, s2);
}

int main(void){
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << isRotation(s1, s2) << endl;
    return 0;
}