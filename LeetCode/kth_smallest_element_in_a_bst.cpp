#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        list<int> res = inorder(root, k);
        for(int i = 0; i < k - 1; i++)
            res.pop_front();
        return res.front();
    }
private:
    list<int> inorder(TreeNode* node, int k) {
        if(!node)
            return list<int>();
        list<int> left = inorder(node->left, k);
        left.push_back(node->val);
        list<int> right = inorder(node->right, k);
        left.merge(right);
        return left;
    }
};

TreeNode* createTree(const vector<int>& nums, int index){
    if(index >= nums.size())
        return nullptr;
    TreeNode* node = new TreeNode(nums[index]);
    node->left = createTree(nums, index * 2 + 1);
    node->right = createTree(nums, (index + 1) * 2);
    return node;
}

TreeNode* createTree(const vector<int>& nums){
    return createTree(nums, 0);
}

int main(void){
    vector<int> nums = {3, 1, 5, 0, 2, 4, 6};
    TreeNode* root = createTree(nums);
    Solution sol;
    cout << sol.kthSmallest(root, 5) << endl;
    return 0;
}