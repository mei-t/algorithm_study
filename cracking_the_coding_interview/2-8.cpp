#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// nodeのvalueは重複なしとする
// 必ず循環するとする
struct Node{
    int val;
    Node* next;
};

Node* findRoop(Node* node, unordered_set<int>* nodeSet){
    if(nodeSet->find(node->val) != nodeSet->end()){
        return node;
    }
    nodeSet->insert(node->val);
    return findRoop(node->next, nodeSet);
}

Node* findRoop(Node* root){
    unordered_set<int> nodeSet;
    return findRoop(root, &nodeSet);
}

Node* insert(const vector<int>& nums, size_t i, size_t roopIndex, Node* roopNode = nullptr){
    if(i == nums.size() - 1){
        return roopNode;
    }
    Node* node = new Node;
    node->val = nums[i];
    if(i == roopIndex){
        roopNode = node;
    }
    node->next = insert(nums, i + 1, roopIndex, roopNode);
    return node;
}

int main(void){
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* root = insert(nums, 0, 5);
    Node* roopNode = findRoop(root);
    cout << roopNode->val << endl;
    return 0;
}