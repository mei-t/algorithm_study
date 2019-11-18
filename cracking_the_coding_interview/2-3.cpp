#include <iostream>
using namespace std;

// 3分16秒 +α (間違ってた)

struct Node{
    int val;
    Node* next;
};

void deleteMiddleNode(Node* node){
    Node* delNode = node->next;
    *node = *node->next; // *(node -> next)
    delete delNode;
}

int main(void){
    Node* node0 = new Node;
    node0->val = 0;
    Node* node1 = new Node;
    node0->next = node1;
    node1->val = 1;
    Node* node2 = new Node;
    node1->next =  node2;
    node2->val = 2;
    cout << node0->next->val << endl;
    deleteMiddleNode(node1);
    cout << node0->next->val << endl;
    return 0;
}