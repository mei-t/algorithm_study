#include <iostream>
#include <cassert>
using namespace std;

string urlify(char* s, const size_t size){
    int count = 0;
    for(int i=0; i<=size; i++){
        if(s[i] == ' '){
            count++;
        }
    }
    size_t newStrIndex = size + count * 2;
    size_t originStrIndex = size;
    s[newStrIndex + 1] = '\0';
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
    char *s = (char*)malloc(100); // new char[100]
    strcpy(s, "This is a pen.");
    urlify(s, 13);
    cout << s << endl;
    cout << strcmp(s, "This%20is%20a%20pen.") << endl;
    assert(strcmp(s, "This%20is%20a%20pen.") == 0);
    return 0;
}