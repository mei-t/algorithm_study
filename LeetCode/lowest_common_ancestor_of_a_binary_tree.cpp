#include <iostream>
#include <utility>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<int, TreeNode*> res = findLca(root, p, q);
        return res.second;
    }

    pair<int, TreeNode*> findLca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node)
            return pair<int, TreeNode*>(0, nullptr);
        int find_node = 0;
        if(node == p || node == q)
            find_node++;
        pair<int, TreeNode*> l_res = findLca(node->left, p, q);
        find_node += l_res.first;
        if(find_node == 2){
            if(l_res.first == 2)
                return l_res;
            return pair<int, TreeNode*>(2, node);
        }
        pair<int, TreeNode*> r_res = findLca(node->right, p, q);
        find_node += r_res.first;
        if(find_node < 2)
            return pair<int, TreeNode*>(find_node, nullptr);
        if(r_res.first == 2)
            return r_res;
        return pair<int, TreeNode*>(2, node);
    }
};

int main(void){
    return 0;
}