#include <iostream>
#include <cassert>
using namespace std;

string urlify(char* s, const size_t& size){
    int count = 0;
    for(int i=0; i<=size; i++){
        if(s[i] == ' '){
            count++;
        }
    }
    size_t newStrIndex = size + count * 2;
    size_t originStrIndex = size;
    s[newStrIndex + 1] = '\n';
    while(count > 0){
        if(s[originStrIndex] == ' '){
            s[newStrIndex--] = '0';
            s[newStrIndex--] = '2';
            s[newStrIndex--] = '%';
            originStrIndex--;
            count--;
        }else{
            s[newStrIndex--] = s[originStrIndex--];
        }
    }
    return s;
}

int main(void){
    char s[] = "This is a pen.";
    cout << urlify(s, 13) << endl;
    assert(urlify(s, 13) == "This%20is%20a%20pen.");
    return 0;
}