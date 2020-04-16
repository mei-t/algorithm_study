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

class Solution1 {
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

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        makeCopyNode(head);
        makeRandomLink(head);
        return separateCopyFromOriginal(head);
    }
private:
    void makeCopyNode(Node* node){
        if(!node){
            return;
        }
        Node* copyNode = new Node(node->val);
        copyNode->next = node->next;
        node->next = copyNode;
        makeCopyNode(copyNode->next);
    }

    void makeRandomLink(Node* node){
        if(!node){
            return;
        }
        Node* copyNode = node->next;
        copyNode->random = node->random ? node->random->next : nullptr;
        makeRandomLink(copyNode->next);
    }

    Node* separateCopyFromOriginal(Node* node){
        if(!node){
            return nullptr;
        }
        Node* copyNode = node->next;
        node->next = copyNode->next;
        copyNode->next = separateCopyFromOriginal(copyNode->next);
        return copyNode;
    }
};

int main(void){
    return 0;
}