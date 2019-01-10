#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include <iostream>

struct Node{
    int key;
    Node *prev, *next;
};

Node *nil;

void Init(){
    nil = (Node *)malloc(sizeof(Node));
    nil -> prev = nil;
    nil -> next = nil;
    return;
}

void Insert(int insert_key){
    // 挿入するノード宣言してキーの値を入れる
    Node *x = (Node *)malloc(sizeof(Node));
    x -> key = insert_key;
    
    // 番兵の直後に要素を追加
    x -> next = nil -> next;
    nil -> next -> prev = x;
    x -> prev = nil;
    nil -> next = x;
    return;
}

Node* Search(int search_key){
    Node *current = nil -> next;
    while(current != nil && current -> key != search_key){
        current = current -> next;
    }
    return current; 
}

void Delete(Node *x){
    if(x == nil){return;}
    x -> prev -> next = x -> next;
    x -> next -> prev = x -> prev;
    free(x);
    return;
}

void DeleteFirtst(){
    Delete(nil -> next);
    return;
}

void DeleteLast(){
    Delete(nil -> prev);
    return;
}

void Output(){
    Node *x = nil -> next;
    while(x != nil){
        printf("%d", x -> key);
        if(x -> next != nil){printf(" ");}
        else{printf("\n");}
        x = x -> next;
    }
    return;
}

int main(void){
    Init();
    int n;
    scanf("%d", &n);
    char command[12];
    int key;
    for(int i=0; i<n; i++){
        scanf("%s%d", command, &key);
        if(!strcmp(command, "insert")){Insert(key);}
        else if(!strcmp(command, "delete")){Delete(Search(key));}
        else if(!strcmp(command, "deleteFirst")){DeleteFirtst();}
        else {DeleteLast();}
    }
    Output();
    return 0;
}