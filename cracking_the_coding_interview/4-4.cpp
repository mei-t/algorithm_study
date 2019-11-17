#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct Node{
    Node* left;
    Node* right;
};

bool isBalanceTree(Node* root){ // constにすると"no matching member function for call to 'push'"
    if(!root){
        return true; // nodeが存在しないならtrue
    }
    queue<pair<Node*, int>> nodeQueue;
    nodeQueue.push(make_pair(root, 0));
    int minDepth = -1;
    while(!nodeQueue.empty()){
        pair<Node*, int> nodeData = nodeQueue.front();
        nodeQueue.pop();

        // 左側
        if(nodeData.first -> left != nullptr){
            nodeQueue.push(make_pair(nodeData.first -> left, nodeData.second + 1));
        }else if(minDepth == -1){
            minDepth = nodeData.second; // BFSなので最初に見つかった要素のdepthがminDepthになる
        }else if(minDepth + 1 < nodeData.second){
            return false; // 最小の深さよし1以上大きかったらfalse
        }

        //右側
        if(nodeData.first -> right != nullptr){
            nodeQueue.push(make_pair(nodeData.first -> right, nodeData.second + 1));
        }else if(minDepth == -1){
            minDepth = nodeData.second; // BFSなので最初に見つかった要素のdepthがminDepthになる
        }else if(minDepth + 1 < nodeData.second){
            return false; // 最小の深さよし1以上大きかったらfalse
        }
    }
    return true;
}

Node* createLeftNode(Node* parent){
    Node* node = new Node;
    parent -> left = node;
    return node;
}

Node* createRightNode(Node* parent){
    Node* node = new Node;
    parent -> right = node;
    return node;
}

int main(void){
    Node* root0 = new Node;
    Node* left0 = createLeftNode(root0);
    Node* right0 = createRightNode(root0);
    createLeftNode(left0);
    createLeftNode(right0);
    cout << isBalanceTree(root0) << endl; // ture

    Node* root1 = new Node;
    Node* left1 = createLeftNode(root1);
    createLeftNode(left1);
    cout << isBalanceTree(root1) << endl; // false
    return 0;
}