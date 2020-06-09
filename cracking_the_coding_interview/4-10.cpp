#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool isSubTree(TreeNode* t1, TreeNode* t2) {
    if(!t1)
        return !t2;
    if(t1->val != t2->val)
        return false;
    bool leftSubTree = isSubTree(t1->left, t2->left);
    bool rightSubTree = isSubTree(t1->right, t2->right);
    return leftSubTree && rightSubTree;
}

bool searchSubTree(TreeNode* t1, TreeNode* t2) {
    if(!t1)
        return !t2;
    if(!t2)
        return false;
    if(t1->val == t2->val) {
        bool subTree = isSubTree(t1, t2);
        if(subTree)
            return true;
    }
    bool leftSubTree = searchSubTree(t1->left, t2);
    bool rightSubTree = searchSubTree(t1->right, t2);
    return leftSubTree || rightSubTree;
}

TreeNode* makeTree(vector<int>& nums, int index){
    if(index >= nums.size()){
        return nullptr;
    }
    if(nums[index] == -1){
        return nullptr;
    }
    TreeNode* node = new TreeNode();
    node->val = nums[index];
    node->left = makeTree(nums, (index + 1) * 2 - 1);
    node->right = makeTree(nums, (index + 1) * 2);
    return node;
}

void outputTree(TreeNode* node) {
    if(!node)
        return;
    cout << node->val << endl;
    outputTree(node->left);
    outputTree(node->right);
}

int main(void){
    vector<int> nums1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> nums2 = {9, 10, 11};
    TreeNode* t1 = makeTree(nums1, 0);
    TreeNode* t2 = makeTree(nums2, 0);
    outputTree(t1);
    cout << (searchSubTree(t1, t2) ? "true" : "false") << endl;
    vector<int> nums3 = {2, 5, 6};
    TreeNode* t3 = makeTree(nums3, 0);
    cout << (searchSubTree(t1, t3) ? "true" : "false") << endl;
    return 0;
}