#include <iostream>
#include <random>
using namespace std;

struct TreeNode {
    int val;
    int leftCount;
    int rightCount;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
public:
    void insertNode(int val) {
        root = insertNode(val, root);
    }

    void deleteNode(int val) {}

    TreeNode* getRandomNode(TreeNode* node) {
        if(!node)
            return nullptr;
        int range = node->leftCount + node->rightCount;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, range);
        int x = dis(gen);
        if(x == 0)
            return node;
        if(x <= node->leftCount)
            return getRandomNode(node->left);
        return getRandomNode(node->right);
    }
private:
    TreeNode* root;
    TreeNode* insertNode(int val, TreeNode* node) {
        if(!node) {
            node = new TreeNode{val, 0, 0, nullptr, nullptr};
            return node;
        }
        if(val < node->val) {
            node->leftCount++;
            TreeNode* leftNext = insertNode(val, node->left);
            if(!node->left)
                node->left = leftNext;
            return node;
        }
        node->rightCount++;
        TreeNode* rightNext = insertNode(val, node->right);
        if(!node->right)
            node->right = rightNext;
        return node;
    }
};

int main(void){
    return 0;
}