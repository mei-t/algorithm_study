#include <iostream>
#include <vector>
using namespace std;

// 15分17秒

struct Node{
    int val;
    Node* next;
};

void checkList(Node* node, vector<int>& numList){
    if(!node){
        return;
    }

    numList.push_back(node->val);
    checkList(node->next, numList);
}

bool isPalindrome(Node* root){
    vector<int> numList;
    checkList(root, numList);
    auto fromTop = numList.begin();
    auto fromEnd = numList.end();
    fromEnd--;
    for(int i=0; i < numList.size() - 1 / 2; i++){
        if(*fromTop != *fromEnd){
            return false;
        }
        fromTop++;
        fromEnd--;
    }
    return true;
}

Node* createNode(const vector<int>& v, int i){
    if(i == v.size()){
        return nullptr;
    }
    Node* node = new Node;
    node->val = v[i];
    node->next = createNode(v, i+1);
    return node;
}

int main(void){
    vector<int> v1 = {0, 1, 4, 2, 4, 1, 0};
    Node* node1 = createNode(v1, 0);
    cout << isPalindrome(node1) << endl;
    vector<int> v2 = {0, 1, 4, 2, 9, 4, 1, 0};
    Node* node2 = createNode(v2, 0);
    cout << isPalindrome(node2) << endl;
    return 0;
}