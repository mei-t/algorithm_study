#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindromePermu(string s){
    unordered_set<char> charSet;
    transform(s.begin(), s.end(), s.begin(),[](unsigned char c) -> unsigned char {return tolower(c);});
    for(char c: s){
        if(c != ' '){
            if(charSet.find(c) == charSet.end()){
                charSet.insert(c);
            }else{
                charSet.erase(c);
            }
        }
    }

    if(charSet.size() > 1){
        return false;
    }
    return true;
}

void test(bool output, bool expected, int testIndex){
    if(output == expected){
        cout << "test " << testIndex << " successed." << endl;
    }else{
        cout << "test " << testIndex << " failed." << endl;
    }
}

int main(void){
    test(isPalindromePermu("Tact Coa"), true, 0);
    test(isPalindromePermu("cat"), false, 1);
    test(isPalindromePermu("   "), true, 2);
    return 0;
}