#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
private:
    bool isValidBST(TreeNode* node, long max, long min){
        if(!node){
            return true;
        }else if(node->val >= max || node->val <= min){
            return false;
        }
        return isValidBST(node->left, node->val, min) && isValidBST(node->right, max, node->val);
    }
};

int main(void){
    TreeNode root(2);
    TreeNode left(1);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    Solution sol;
    cout << sol.isValidBST(&root) << endl;
    return 0;
}