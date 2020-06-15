#include <iostream>
#include <unordered_map>
using namespace std;

class RankOfNumber {
public:
    RankOfNumber() : root(nullptr){}
    void track(int x);
    int getRankOfNumber(int x);
private:
    unordered_map<int, int> rankMap;
    struct TreeNode {
        int val;
        int count;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
    void track(int x, TreeNode* node);
    int getRankOfNumber(int x, int count, TreeNode* node);
};

void RankOfNumber::track(int x){
    if(root){
        track(x, root);
        return;
    }
    root = new TreeNode();
    root->val = x;
    root->count = 0;
}

int RankOfNumber::getRankOfNumber(int x){
    return getRankOfNumber(x, 0, root);
}

void RankOfNumber::track(int x, TreeNode* node){
    if(!node){
        node = new TreeNode();
        node->val = x;
        node->count = 0;
        return;
    }
    // cout << node->val << endl;
    if(x == node->val){
        node->count++;
        return;
    }
    if(x < node->val){
        node->val++;
        track(x, node->left);
        return;
    }
    track(x, node->right);
    return;
}

int RankOfNumber::getRankOfNumber(int x, int count, TreeNode* node){
    if(!node){
        return -1;
    }
    cout << node->val << endl;
    if(x == node->val)
        return count + node->count;
    if(x < node->val)
        return getRankOfNumber(x, count, node->left);
    return getRankOfNumber(x, count + node->val + 1, node->right);
}

int main(void){
    RankOfNumber ron;
    ron.track(5);
    cout << "aa" << endl;
    ron.track(1);
    ron.track(4);
    ron.track(4);
    ron.track(5);
    ron.track(9);
    ron.track(7);
    ron.track(13);
    ron.track(3);
    cout << "aa" << endl;
    // cout << ron.getRankOfNumber(1) << endl; // 0
    // cout << ron.getRankOfNumber(3) << endl; // 1
    cout << ron.getRankOfNumber(4) << endl; // 3
    return 0;
}