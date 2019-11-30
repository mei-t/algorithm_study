#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// 24分2秒(テスト含む)

struct Node{
    int val;
    Node* next;
};

void createNodeSet(Node* node, unordered_set<Node*>& nodeSet){
    if(!node || nodeSet.count(node)){
        return;
    }
    nodeSet.insert(node);
    createNodeSet(node->next, nodeSet);
}

Node* findNode(Node* node, unordered_set<Node*>& nodeSet1, unordered_set<Node*>& nodeSet2){
    if(!node || nodeSet2.count(node)){
        return nullptr;
    }
    if(nodeSet1.count(node)){
        return node;
    }
    nodeSet2.insert(node);
    return findNode(node->next, nodeSet1, nodeSet2);
}

Node* findCommonNode(Node* root1, Node* root2){
    unordered_set<Node*> nodeSet1;
    createNodeSet(root1, nodeSet1);
    unordered_set<Node*> nodeSet2;
    return findNode(root2, nodeSet1, nodeSet2);
}

Node* createNode(vector<int> nums, int i = 0){
    if(i == nums.size()){
        return nullptr;
    }
    Node* node = new Node;
    node->val = nums[i];
    node->next = createNode(nums, i+1);
    return node;
}

Node* findNode(Node* node, int num){
    if(!node){
        return nullptr;
    }
    if(node->val == num){
        return node;
    }
    return findNode(node->next, num);
}

int main(void){
    vector<int> v1 = {23, 42, 15, 232, 1, 58, 90, 3, 735, 63};
    Node* root1 = createNode(v1);
    Node* jSegment = findNode(root1, 90);
    vector<int> v2 = {80, 375, 73, 6, 36, 93, 33};
    Node* root2 = createNode(v2);
    Node* root2End = findNode(root2, 33);
    root2End->next = jSegment;
    Node* node = findCommonNode(root1, root2);
    if(!node){
        cout << "false" << endl;
    }else{
        cout << "true" << endl;
        cout << "The common node is " << node->val << endl;
    }
    return 0;
}