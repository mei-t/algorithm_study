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
    BinaryTree() : root(nullptr) {}
    void insertNode(int val) {
        TreeNode** curNodePtr = &root;

        while(*curNodePtr != nullptr) {
            TreeNode* curNode = *curNodePtr;
            if(val < curNode->val) {
                curNode->leftCount++;
                curNodePtr = &curNode->left;
            }else if(val > curNode->val) {
                curNode->rightCount++;
                curNodePtr = &curNode->right;
            }else{
                return; // The value is already in the tree.
            }
        }
        *curNodePtr = new TreeNode{val, 0, 0, nullptr, nullptr};
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
};

int main(void){
    return 0;
}