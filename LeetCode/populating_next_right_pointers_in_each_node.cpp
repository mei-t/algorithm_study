#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        connectPartly(root);
        return root;
    }
private:
    queue<pair<Node*, Node*>> connectPartly(Node* node) {
        if(!node)
            return queue<pair<Node*, Node*>>();
        queue<pair<Node*, Node*>> lefts = connectPartly(node->left);
        queue<pair<Node*, Node*>> rights = connectPartly(node->right);
        queue<pair<Node*, Node*>> merged;
        while(!lefts.empty()) {
            pair<Node*, Node*> left = lefts.front();
            lefts.pop();
            pair<Node*, Node*> right = rights.front();
            rights.pop();
            left.second->next = right.first;
            merged.push(pair<Node*, Node*>(left.first, right.second));
        }
        merged.push(pair<Node*, Node*>(node, node));
        return merged;
    }
};

Node* createTree(const vector<int>& nums, int index) {
    if(index > nums.size())
        return nullptr;
    Node* node = new Node(nums[index - 1]);
    node->left = createTree(nums, index * 2);
    node->right = createTree(nums, index * 2 + 1);
    return node;
}

Node* createTree(const vector<int>& nums) {
    return createTree(nums, 1);
}

int main(void){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Node* root = createTree(nums);
    Solution sol;
    sol.connect(root);
    return 0;
}