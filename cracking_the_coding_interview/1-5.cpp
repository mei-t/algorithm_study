#include <iostream>
using namespace std;

bool canChangeOnece(string s1, string s2){
    string shortString, longString;
    if(s1.size() <= s2.size()){
        shortString = s1;
        longString = s2;
    }else{
        shortString = s2;
        longString = s1;
    }
    int diff = longString.size() - shortString.size();
    if(diff == 0){
        bool isDiff = false;
        for(int i=0; i<shortString.size(); i++){
            if(shortString[i] != longString[i]){
                if(isDiff){
                    return false;
                }
                isDiff = true;
            }
        }
    }else if(diff == 1){
        int shortIndex = 0;
        int longIndex = 0;
        while(shortIndex < shortString.size()){
            if(shortString[shortIndex] != longString[longIndex]){
                if(shortIndex != longIndex || shortString[shortIndex] != longString[++longIndex]){
                    return false;
                }
            }
            shortIndex++;
            longIndex++;
        }
    }else{
        return false;
    }
    return true;
}

int main(void){
    cout << canChangeOnece("pale", "bale") << endl;
    cout << canChangeOnece("pale", "bake") << endl;
    return 0;
}