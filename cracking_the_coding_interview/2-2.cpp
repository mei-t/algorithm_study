#include <iostream>
using namespace std;
#define nil -1

struct Node{
  int key;
  Node *next;
};

// Node *T[100];

void insert(Node *head){
  Node *newNode = new Node();
  newNode -> key = 3;
  newNode -> next = head;
  
}

// Tの次のNodeを削除する
void deleteNextNode(Node *T){
  Node *tmp = T->next;
  T->next = T->next->next;
  delete tmp;
}

// 重複要素の削除
void deleteDuplicate(Node *T){
  //bool *isFirst = (bool*)malloc(4*sizeof(bool));
  bool *isFirst = new bool[256]; // initialize必要

  while(T -> next -> next -> key != nullptr){
    T = T -> next;
    if(isFirst[T -> next -> key]){
      deleteNextNode(T);
    }else{
      isFirst[T -> next -> key] = true;
    }
  }
}

// 発展問題:一時的なバッファが使用できない場合
void deleteDuplicateNoBuffer(Node *T){
  Node *T2;

  while (T -> next -> next -> key != nil){
    T2 = T -> next -> next;
    while (T2 -> next -> key != nil){
      if (T -> next == T2){
        deleteNextNode(T);
        break;
      }
      T2 = T2 -> next;
    }
    T = T -> next;
  }
}

int main(void){
  Node *head = nullptr;
  insert(head);
  deleteDuplicate(head);
  return 0;
}
