#include <iostream>
#include <cassert>
using namespace std;

// 10分28
string urlify(string s){
    int i = 0;
    while(i != s.size()){
        if(s[i] == ' '){
            s.replace(i, 1, "%20");
            i += 2;
        }
        i++;
    }
    return s;
}

int main(void){
    cout << urlify("This is a pen.") << endl;
    assert(urlify("This is a pen.") == "This%20is%20a%20pen.");
    return 0;
}