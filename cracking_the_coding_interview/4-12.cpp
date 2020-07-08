#include <iostream>
#include <queue>
using namespace std;

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
        curSum += cur;
        if(curSum == given)
            res++;
    }
    queue<int> c(q);
    res += countRoute(node->left, sum, given, q);
    res += countRoute(node->right, sum, given, c);
    return res;
}

int countRoute(Node* root, int given){
    queue<int> q;
    return countRoute(root, 0, given, q);
}

int main(void){
    return 0;
}