#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define NULLPTR INT_MAX + 1

struct Node{
    int val;
    Node* left;
    Node* right;
};

int countRoute(Node* node, int sum, int given, queue<int>& q){
    if(!node)
        return 0;
    sum += node->val;
    int res = 0;
    if(sum == given)
        res++;
    int curSum = sum;
    for(int i = 0; i < q.size(); i++){
        int cur = q.front();
        q.pop();
        q.push(cur);
        curSum -= cur;
        if(curSum == given)
            res++;
    }
    q.push(node->val);
    queue<int> c(q);
    res += countRoute(node->left, sum, given, q);
    res += countRoute(node->right, sum, given, c);
    return res;
}

int countRoute(Node* root, int given){
    queue<int> q;
    return countRoute(root, 0, given, q);
}

Node* buildTree(const vector<long>& nums, int index) {
    if(index >= nums.size() || nums[index] == NULLPTR)
        return nullptr;
    Node* node = new Node{(int)nums[index]};
    node->left = buildTree(nums, index * 2 + 1);
    node->right = buildTree(nums, index * 2 + 2);
    return node;
}

Node* buildTree(const vector<long>& nums) {
    return buildTree(nums, 0);
}

int main(void){
    vector<long> nums = {10, 5, -3, 3, 2, NULLPTR, 11, 3, -2, NULLPTR, 1};
    Node* root = buildTree(nums);
    int res = countRoute(root, 8);
    cout << res << endl;
    return 0;
}