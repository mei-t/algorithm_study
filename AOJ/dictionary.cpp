#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <bitset>
using namespace std;

int m = 1046527;

long long ChangeToNumber(char str[]){
    long long key = 0;
    for(int i=0; str[i]!='\0'; i++){
        key *= 10;

        // if文よりswitch文を使ったほうが見やすい。
        switch(str[i]){
            case 'A':
                key += 1;
            case 'C':
                key += 2;
            case 'G':
                key += 3;
            case 'T':
                key += 4;
        }
    }
    return key;
}

int h1(long long key){ return key % m; }
int h2(long long key){ return 1 + (key % (m-1)); }

int h(long long key, int i){ return (h1(key) + i * h2(key)) % m; }

void Insert(long long T[], long long key){
    int i = 0;
    while(true){
        int j = h(key, i);
        if(j>1046527){
            i += 1;
        }else if(T[j] == NULL){
            T[j] = key;
            return;
        }else{
            i += 1;
        }
    }
    return;
}

void Search(long long T[], long long key){
    int i = 0;
    while(true){
        int j = h(key, i);
        if(j>1046527){
            i += 1;
        }else if(T[j] == key){
            printf("yes\n");
            return;
        }else if(T[j] == NULL){
            printf("no\n");
            return;
        }else{
            i += 1;
        }
    }
    return;
}

// 4文字のアルファベット(A, C, G, T)
// 文字列の最大の長さは12文字
int main(void){
    // mallocは初期化されないメモリが渡される。
    // memsetで初期化をすること
    long long *T = (long long*)malloc(1046527*sizeof(long long));
    memset(T, 0, 1046527*sizeof(long long));
    int n;
    scanf("%d", &n);

    char order[7];
    char str[13];
    long long key;
    for(int i=0; i<n; i++){
        scanf("%s%s", order, str);

        key = ChangeToNumber(str);
        if(order[0]=='i'){ Insert(T, key); }
        else{ Search(T, key); }
    }
    return 0;
}