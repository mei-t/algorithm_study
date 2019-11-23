#include <iostream>
#include <vector>
#include <utility>
#include <charconv>
using namespace std;

void stringCompression(char* s, const size_t size){
    int count = 1;
    int diff = 0;
    vector<pair<char, int>> charList;
    for(int i=1; i<size; i++){
        cout << i << endl;
        if(s[i] != s[i-1]){
            charList.push_back(make_pair(s[i-1], count));
            diff += count - 2;
            count = 1;
        }else{
            count++;
        }
    }

    if(diff <= 0){
        return;
    }

    int i = 0;
    for(auto pair: charList){
        cout << "aa" << endl;
        s[i] = pair.first;
        cout << "bb" << endl;
        s[i+1] = pair.second;
        cout << "cc" << endl;
        i += 2;
    }
    s[size - diff] = '\0';
    return;
}

int main(void){
    char *s = (char*)"aaabbcccccd";
    stringCompression(s, strlen(s) + 1);
    cout << s << endl;
    return 0;
}