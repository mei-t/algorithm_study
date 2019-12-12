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

Node* findLoop(Node* node, unordered_set<int>* nodeSet){
    if(nodeSet->find(node->val) != nodeSet->end()){
        return node;
    }
    nodeSet->insert(node->val);
    return findLoop(node->next, nodeSet);
}

Node* findLoop(Node* root){
    unordered_set<int> nodeSet;
    return findLoop(root, &nodeSet);
}

Node* findLoop2(Node* fromStart, Node* fromMeetingPoint){
    if(fromStart == fromMeetingPoint){
        return fromStart;
    }
    return findLoop2(fromStart->next, fromMeetingPoint->next);
}

Node* findMeetingPoint2(Node* slow, Node* fast){
    if(slow == fast){
        return slow;
    }
    return findMeetingPoint2(slow->next, fast->next->next);
}

Node* findLoop2(Node* root){
    Node* meetingPoint = findMeetingPoint2(root->next, root->next->next);
    return findLoop2(root, meetingPoint);
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
    Node* roopNode = findLoop(root);
    cout << roopNode->val << endl;
    Node* roopNode2 = findLoop2(root);
    cout << roopNode2->val << endl;
    return 0;
}