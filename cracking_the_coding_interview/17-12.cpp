#include <iostream>
using namespace std;

class BiNode{
public:
    BiNode* node1;
    BiNode* node2;
};

BiNode* convertLeft(BiNode* node);
BiNode* convertRight(BiNode* node);

BiNode* rightEnd(BiNode* node){
    if(!node->node2){
        return node;
    }
    return rightEnd(node->node2);
}

BiNode* leftEnd(BiNode* node){
    if(!node->node1){
        return node;
    }
    return leftEnd(node->node1);
}

BiNode* convertLeft(BiNode* node){
    if(!node){
        return nullptr;
    }
    node->node1 = convertLeft(node->node1);
    node->node2 = convertRight(node->node2);
    return rightEnd(node);
}

BiNode* convertRight(BiNode* node){
    if(!node){
        return nullptr;
    }
    node->node1 = convertLeft(node->node1);
    node->node2 = convertRight(node->node2);
    return leftEnd(node);
}

BiNode* createLinkedList(BiNode* root){
    root->node1 = convertLeft(root->node1);
    root->node2 = convertRight(root->node2);
    return leftEnd(root);
}

int main(void){
    return 0;
}