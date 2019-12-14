#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* parent;
    Node* left;
    Node* right;
};

// parentにアクセスできる場合、BigOの考え方的に時間計算量・空間計算量ともに最適な方法
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

// parentにアクセスできない場合
Node* findFirstCommonNode(Node* node1, Node* node2, Node* node){
    if(!node){
        return nullptr;
    }else if(node == node1 || node == node2){
        return node;
    }
    Node* left = findFirstCommonNode(node1, node2, node->left);
    if(left && left != node1 && left != node2){
        return left;
    }
    Node* right = findFirstCommonNode(node1, node2, node->right);
    if((left == node1 && right == node2) || (left == node2 && right == node1)){
        return node;
    }else if(!left){
        return right;
    }
    return left;
}

int main(void){
    return 0;
}