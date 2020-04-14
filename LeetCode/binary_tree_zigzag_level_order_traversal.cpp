#include <iostream>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        sideLevelOrder(root, 0, ans);
        makeZigzag(ans);
        return ans;
    }
private:
    void sideLevelOrder(TreeNode* node, int level, vector<vector<int>>& ans){
        if(!node){
            return;
        }
        if(ans.size() < level + 1){
            ans.push_back(vector<int>());
        }
        ans[level].push_back(node->val);
        sideLevelOrder(node->left, level + 1, ans);
        sideLevelOrder(node->right, level + 1, ans);
    }

    void makeZigzag(vector<vector<int>>& ans){
        for(int i = 1; i < ans.size(); i += 2){
            cout << "i = " << i << endl;
            for(int j = 0; j < ans[i].size() / 2; j++){
                swap(ans[i][j], ans[i][ans[i].size() - j - 1]);
            }
        }
    }
};

int main(void){
    TreeNode* root;
    return 0;
}