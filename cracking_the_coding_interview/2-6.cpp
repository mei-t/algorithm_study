#include <iostream>
#include <vector>
using namespace std;

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
    for(int i=0; i < numList.size() - 1 / 2; i++){
        if(*fromTop != *fromEnd){
            return false;
        }
        fromTop++;
        fromEnd--;
    }
    return false;
}

int main(void){
    return 0;
}