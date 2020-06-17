#include <iostream>
#include <unordered_map>
using namespace std;

class RankOfNumber {
public:
    RankOfNumber() : root(nullptr){}
    void track(int x){
        root = track(x, root);
    }

    int getRankOfNumber(int x){
        return getRankOfNumber(x, 0, root);
    }

private:
    unordered_map<int, int> rankMap;
    struct TreeNode {
        int val;
        int count;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
    TreeNode* track(int x, TreeNode* node) {
        if(!node){
            node = new TreeNode();
            node->val = x;
            node->count = 0;
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }
        // cout << node->val << endl;
        if(x == node->val){
            node->count++;
            return node;
        }
        if(x < node->val){
            node->count++;
            TreeNode* next = track(x, node->left);
            if(!(node->left))
                node->left = next;
            return node;
        }
        TreeNode* next = track(x, node->right);
        if(!(node->right))
            node->right = next;
        return node;
    }

    int getRankOfNumber(int x, int count, TreeNode* node){
        // cout << node->val << endl;
        if(x == node->val)
            return count + node->count;
        if(x < node->val)
            return getRankOfNumber(x, count, node->left);
        return getRankOfNumber(x, count + node->val + 1, node->right);
    };
};

int main(void){
    RankOfNumber ron;
    ron.track(5);
    ron.track(1);
    ron.track(4);
    ron.track(4);
    ron.track(5);
    ron.track(9);
    ron.track(7);
    ron.track(13);
    ron.track(3);
    cout << ron.getRankOfNumber(1) << endl; // 0
    cout << ron.getRankOfNumber(3) << endl; // 1
    cout << ron.getRankOfNumber(4) << endl; // 3
    return 0;
}