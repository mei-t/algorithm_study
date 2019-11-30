#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;

// 24分2秒(テスト含む)

struct Node{
    int val;
    Node* next;
};

struct CommonNodeData{
    bool isFound;
    Node* commonNode;
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

pair<Node*, int> findLastNode(Node* node, int len = 1){
    if(!node->next){
        return make_pair(node, len);
    }
    return findLastNode(node->next, len+1);
}

Node* nextNode(Node* node, int i){
    if(i == 0){
        return node;
    }
    return nextNode(node->next, i-1);
}

Node* findNode2(Node* node1, Node* node2){
    if(node1 == node2){
        return node1;
    }
    return findNode2(node1->next, node2->next);
}

CommonNodeData findCommonNode2(Node* root1, Node* root2){
    Node copyRoot1 = *root1;
    Node copyRoot2 = *root2;
    pair<Node*, int> lastNode1 = findLastNode(&copyRoot1);
    pair<Node*, int> lastNode2 = findLastNode(&copyRoot2);
    CommonNodeData cnd;
    if(lastNode1.first != lastNode2.first){
        cnd.isFound = false;
        return cnd;
    }
    cnd.isFound = true;
    Node* longNode = lastNode1.second > lastNode2.second ? root1 : root2;
    Node* shortNode = lastNode1.second <= lastNode2.second ? root1 : root2;
    longNode = nextNode(longNode, abs(lastNode1.second - lastNode2.second));
    cnd.commonNode = findNode2(longNode, shortNode);
    return cnd;
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

    Node copyRoot1 = *root1;
    Node copyRoot2 = *root2;
    Node* node = findCommonNode(&copyRoot1, &copyRoot2);
    if(!node){
        cout << "false" << endl;
    }else{
        cout << "true" << endl;
        cout << "The common node is " << node->val << endl;
    }

    CommonNodeData cnd = findCommonNode2(root1, root2);
    if(!cnd.isFound){
        cout << "false" << endl;
    }else{
        cout << "true" << endl;
        cout << "The common node is " << cnd.commonNode->val << endl;
    }
    return 0;
}