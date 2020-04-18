#include <iostream>
using namespace std;

bool isSubstring(string& s1, string& s2){
    if(s1.size() != s2.size()){
        return false;
    }
    int size = s1.size();
    for(int i = 0; i < size; i++){
        bool isAllSame = true;
        for(int j = 0; j < size; j++){
            if(s1[j] != s2[(i + j) % size]){
                isAllSame = false;
                break;
            }
        }
        if(isAllSame){
            return true;
        }
    }
    return false;
}

int main(void){
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << isSubstring(s1, s2) << endl;
    return 0;
}