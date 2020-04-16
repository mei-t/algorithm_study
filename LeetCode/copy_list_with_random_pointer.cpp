#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
       vector<Node*> nodeList;
       Node* copyHead =  makeCopyNode(head, nodeList);
       makeRandomLink(head, copyHead, nodeList);
       return copyHead;
    }
private:
    Node* makeCopyNode(Node* node, vector<Node*>& nodeList){
        if(!node){
            return nullptr;
        }
        Node* copyNode = new Node(node->val);
        node->val = nodeList.size();
        nodeList.push_back(copyNode);
        copyNode->next = makeCopyNode(node->next, nodeList);
        return copyNode;
    }

    void makeRandomLink(Node* node, Node* copyNode, vector<Node*>& nodeList){
        if(!copyNode){
            return;
        }
        if(!node->random){
            copyNode->random = nullptr;
        }else{
            copyNode->random = nodeList[node->random->val];
        }
        makeRandomLink(node->next, copyNode->next, nodeList);
    }
};

int main(void){
    return 0;
}