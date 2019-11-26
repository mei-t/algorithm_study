#include <iostream>
using namespace std;

// 5分8秒
// 問題を取り間違えているかも知れない

struct Node {
    int val;
    Node* left;
    Node* right;
    // Node* parent;
};

void searchInOrder(Node* node){
    if(!node){
        return;
    }

    searchInOrder(node->left);
    cout << node->val << endl;
    searchInOrder(node->right);
}

int main(void){
    return 0;
}