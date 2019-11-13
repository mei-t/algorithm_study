#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode{
    BinaryTreeNode* pare;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

struct LinkedListNode{
    LinkedListNode* prev;
    LinkedListNode* next;
    BinaryTreeNode* origin;
};

void createList(vector<LinkedListNode*> ans){
    LinkedListNode* pareNode = ans.back();
    LinkedListNode* curNode;
    LinkedListNode* prevNode = nullptr;
    ans.push_back(curNode);
    BinaryTreeNode* pareBTN = pareNode -> origin;
    while(true){
        if(pareBTN -> left != nullptr){
            curNode = new LinkedListNode;
            curNode -> prev = prevNode;
            curNode -> origin = pareBTN -> left;
            prevNode = curNode;
        }
        if(pareBTN -> right != nullptr){
            curNode = new LinkedListNode;
            curNode -> prev = prevNode;
            curNode -> origin = pareBTN -> right;
            prevNode = curNode;
        }
        if(pareNode -> next != nullptr){
            pareNode = pareNode -> next;
            pareBTN = pareNode -> origin;
        }else{
            break;
        }
    }
    if(ans.back() != nullptr){
        createList(ans);
    }
}

vector<LinkedListNode*> depthList(BinaryTreeNode* root){
    vector<LinkedListNode*> ans; // N個のリストの先頭要素のpointer
    LinkedListNode* curNode = new LinkedListNode;
    curNode -> prev = nullptr;
    curNode -> next = nullptr;
    curNode -> origin = root;
    ans.push_back(curNode);
    createList(ans);
    return ans;
}

int main(void){
    return 0;
}