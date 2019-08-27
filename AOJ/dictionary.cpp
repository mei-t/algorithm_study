#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <bitset>
using namespace std;

const int m = 8000000;

int ChangeToNumber(char str[]){
    int key = 0;
    int size = 0;
    for(int i=0; str[i]!='\0'; i++){
        key *= 4;
        size++;

        // if文よりswitch文を使ったほうが見やすい。
        switch(str[i]){
            case 'A':
                key += 0;
                break;
            case 'C':
                key += 1;
                break;
            case 'G':
                key += 2;
                break;
            case 'T':
                key += 3;
                break;
        }
    }
    key += size << 24;
    return key;
}

// 4文字のアルファベット(A, C, G, T)
// 文字列の最大の長さは12文字
int main(void){
    bitset<268435456> T;
    int n;
    scanf("%d", &n);

    char order[7];
    char str[13];
    int key;
    for(int i=0; i<n; i++){
        scanf("%s%s", order, str);

        key = ChangeToNumber(str);
        if(order[0]=='i') {
          T[key] = true;
        }
        else {
          if (T[key])
            printf("yes\n");
          else
            printf("no\n");
        }
    }

    return 0;
}
