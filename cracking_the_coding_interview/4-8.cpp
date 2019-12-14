#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* parent;
    Node* left;
    Node* right;
};

// BigOの考え方的に時間計算量・空間計算量ともに最適な方法
// TC: O(logN) where N is the number of Node.
// SC: O(1)

int findDepth(Node* node, int depth){
    if(!node){
        return depth;
    }
    return findDepth(node->parent, depth + 1);
}

Node* proceedNode(Node* node, int diff){
    if(diff <= 0){
        return node;
    }
    return proceedNode(node->parent, diff - 1);
}

Node* findCommonNode(Node* node1, Node* node2){
    if(node1 == node2){
        return node1;
    }
    return findCommonNode(node1->parent, node2->parent);
}

Node* findFirstCommonNode(Node* node1, Node* node2){
    int depth1 = findDepth(node1, 0);
    int depth2 = findDepth(node2, 0);
    node1 = proceedNode(node1, depth1 - depth2);
    node2 = proceedNode(node2, depth2 - depth1);
    return findCommonNode(node1, node2);
}

int main(void){
    return 0;
}