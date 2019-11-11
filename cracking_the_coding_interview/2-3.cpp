#include <iostream>
using namespace std;

// 3分16秒

struct Node{
    int val;
    Node* next;
};

void deteleMiddleNode(Node* node){
    Node* delNode = node;
    node = node -> next;
    delete delNode;
}

int main(void){
    return 0;
}