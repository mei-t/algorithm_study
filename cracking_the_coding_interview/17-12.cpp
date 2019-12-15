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

// Better approach
// TC: O(N)
// a -> b
void concat(BiNode* a, BiNode* b){
    a->node2 = b;
    b->node1 = a;
}

BiNode* convertToCircular(BiNode* node){
    if(!node){
        return nullptr;
    }

    BiNode* left = convertToCircular(node->node1);
    BiNode* right = convertToCircular(node->node2);

    if(!left && !right){
        concat(node, node);
        return node;
    }

    if(left){
        concat(left->node1, node);
    }else{
        concat(right->node1, node);
    }

    if(right){
        concat(node, right);
    }else{
        concat(node, left);
    }
    if(right){
        concat(right->node1, left);
    }
    return left ? left : node;
}

BiNode* convert(BiNode* root){
    if(!root){
        return root;
    }
    BiNode* node = convertToCircular(root);
    node->node1->node2 = nullptr;
    node->node1 = nullptr;
    return node;
}

int main(void){
    return 0;
}