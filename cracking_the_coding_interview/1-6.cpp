#include <iostream>
#include <vector>
#include <utility>
#include <charconv>
#include <stdlib.h>
#include <stack>
using namespace std;

void stringCompression(char* s, const size_t size){
    int count = 1;
    int diff = 0;
    vector<pair<char, int>> charList;
    for(int i=1; i<size; i++){
        if(s[i] != s[i-1]){
            charList.push_back(make_pair(s[i-1], count));
            diff += count - 1;
            while(count > 0){
                diff--;
                count /= 10;
            }
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
        s[i] = pair.first;
        i++;

        stack<int> numStack;
        int count = pair.second;
        while(count > 0){
            numStack.push(count % 10);
            count /= 10;
        }
        while(!numStack.empty()){
            s[i] = numStack.top() + '0';
            numStack.pop();
            i++;
        }
    }
    s[size - diff - 1] = '\0';
    return;
}

int main(void){
    const char *tmp = "aaabbccccccccccccccccccd";
    size_t size = strlen(tmp) + 1;
    char *s = (char *)malloc(size*sizeof(char));
    strncpy(s, tmp, size);
    cout << s << endl;
    stringCompression(s, strlen(s) + 1);
    cout << s << endl;
    return 0;
}