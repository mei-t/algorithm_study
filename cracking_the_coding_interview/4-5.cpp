#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// 13分27秒

struct Node{
    int val;
    Node* left;
    Node* right;
};

bool isBinarySearchTree(Node* node, int min = INT_MIN, int max = INT_MAX){
    if(!node){
        return true;
    }

    if(min > node->val || max < node->val){
        return false;
    }

    bool isLeftBST = isBinarySearchTree(node->left, min, node->val);
    bool isRightBST = isBinarySearchTree(node->right, node->val, max);

    return isLeftBST && isRightBST;
}

Node* createNewNode(const vector<int>& nums, int left, int right){
    if(left > right){
        return nullptr;
    }
//    cout << left << " " << right << endl;
    Node* current = new Node;
    int mid = (left + right) / 2;
    current->val = nums[mid];
    current->left = createNewNode(nums, left, mid - 1);
    current->right = createNewNode(nums, mid + 1, right);
    return current;
}

void print(Node* node){
    if(!node){
        return;
    }

    print(node->left);
    cout << node->val << " ";
    print(node->right);
}

int main(void){
    vector<int> nums1 = {0, 2, 3, 6, 8, 18, 26, 49};
    vector<int> nums2 = {0, 2, 3, 9, 8, 18, 26, 49};
    Node* root1 = createNewNode(nums1, 0, nums1.size()-1);
    print(root1);
    cout << endl;
    Node* root2 = createNewNode(nums2, 0, nums2.size()-1);
    print(root2);
    cout << endl;
    Node* root3 = nullptr;
    cout << isBinarySearchTree(root1) << endl;
    cout << isBinarySearchTree(root2) << endl;
    cout << isBinarySearchTree(root3) << endl;
    return 0;
}