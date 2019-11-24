#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

struct LinkedListNode{
    int val;
    LinkedListNode* next;
    BinaryTreeNode* origin;
};

void createList(vector<LinkedListNode*>& ans, vector<LinkedListNode*>& tmp, BinaryTreeNode* node, size_t depth){
    if(!node){
        return;
    }

    LinkedListNode *listNode = new LinkedListNode;
    listNode->val = node->val;
    listNode->origin = node;
    listNode->next = nullptr;
    
    if(depth > ans.size()){
        ans.push_back(listNode);
        tmp.push_back(listNode);
    }else{
        listNode->next = tmp[depth];
        tmp[depth] = listNode;
    }

    createList(ans, tmp, node->left, depth+1);
    createList(ans, tmp, node->right, depth+1);
}

vector<LinkedListNode*> depthList(BinaryTreeNode* root){
    vector<LinkedListNode*> ans;
    vector<LinkedListNode*> tmp;
    createList(ans, tmp, root, 1);
    return ans;
}

void deleteNode(vector<LinkedListNode*> ans){
    while(!ans.empty()){
        LinkedListNode* current = ans.back();
        LinkedListNode* next;
        ans.pop_back();
        while(current != nullptr){
            next = current->next;
            delete current;
            current = next;
        }
    }
}

// void createList(vector<LinkedListNode*> ans){
//     LinkedListNode* pareNode = ans.back();
//     LinkedListNode* curNode;
//     LinkedListNode* prevNode = nullptr;
//     BinaryTreeNode* pareBTN = pareNode -> origin;
//     while(true){
//         if(pareBTN -> left != nullptr){
//             curNode = new LinkedListNode;
//             // curNode -> prev = prevNode;
//             curNode -> origin = pareBTN -> left;
//             prevNode = curNode;
//         }
//         if(pareBTN -> right != nullptr){
//             curNode = new LinkedListNode;
//             // curNode -> prev = prevNode;
//             curNode -> origin = pareBTN -> right;
//             prevNode = curNode;
//         }
//         if(pareNode -> next != nullptr){
//             pareNode = pareNode -> next;
//             pareBTN = pareNode -> origin;
//         }else{
//             break;
//         }
//     }
//     ans.push_back(curNode);
//     if(ans.back() != nullptr){
//         createList(ans);
//     }
// }

// vector<LinkedListNode*> depthList2(BinaryTreeNode* root){
//     vector<LinkedListNode*> ans; // N個のリストの先頭要素のpointer
//     LinkedListNode* curNode = new LinkedListNode;
//     // curNode -> prev = nullptr;
//     curNode -> next = nullptr;
//     curNode -> origin = root;
//     ans.push_back(curNode);
//     createList(ans);
//     return ans;
// }

// void deleteNode(vector<LinkedListNode*> ans){
//     while(!ans.back()){
//         LinkedListNode* current = ans.back();
//         LinkedListNode* next;
//         while(current -> next != nullptr){
//             next = current -> next;
//             delete current -> origin;
//             delete current;
//         }
//         delete next -> origin;
//         delete next;
//     }
//     return;
// }

int main(void){
    return 0;
}