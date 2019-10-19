#include <iostream>
using namespace std;

struct Node {
  int key;
  Node* next;
};

// k=1の時、1番最後のkeyを返す
// 最後のnodeの後ろにnullptrがある
// startはnullptrではない
int NthFromTheBack(Node* start, const int k){
  int N = 1;
  Node* current = start;
  if(current == nullptr) {
    throw new exception;
  }

  // Check node count.
  while(current -> next != nullptr){
    N++;
    current = current -> next;
  }

  // Find the Nth node from the back.
  current = start;
  for (int i=0; i<N-k; i++){
    current = current -> next;
  }
  
  return current -> key;
}

int main(void){
  return 0;
}