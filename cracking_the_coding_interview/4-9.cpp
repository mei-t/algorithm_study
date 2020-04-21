#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

void mergeList(list<int>& first, list<int>& second, list<int>& prefix, vector<list<int>>& merged){
    if(first.empty() || second.empty()){
        prefix.splice(prefix.end(), first);
        prefix.splice(prefix.end(), second);
        merged.push_back(prefix);
        return;
    }
    list<int> first1(first);
    list<int> second1(second);
    list<int> prefix1(prefix);
    prefix1.push_back(first1.front());
    first1.pop_front();
    mergeList(first1, second1, prefix1, merged);

    list<int> first2(first);
    list<int> second2(second);
    list<int> prefix2(prefix);
    prefix2.push_back(second2.front());
    second2.pop_front();
    mergeList(first2, second2, prefix2, merged);
}

vector<list<int>> createList(TreeNode* node){
    if(!node){
        vector<list<int>> newList = vector<list<int>>();
        newList.push_back(list<int>());
        return newList;
    }
    vector<list<int>> lefts = createList(node->left);
    vector<list<int>> rights = createList(node->right);
    vector<list<int>> merged;
    // for(list<int>& left: lefts){
    //     for(list<int>& right: rights){
    //         list<int> lfLeft(left);
    //         list<int> lfRight(right);
    //         lfLeft.push_front(node->val);
    //         lfLeft.splice(lfLeft.end(), lfRight);
    //         linked.push_back(lfLeft);

    //         list<int> rfLeft(left);
    //         list<int> rfRight(right);
    //         rfRight.push_front(node->val);
    //         rfRight.splice(rfRight.end(), rfLeft);
    //         linked.push_back(rfRight);
    //     }
    // }
    for(list<int>& left: lefts){
        for(list<int>& right: rights){
            list<int> prefix;
            mergeList(left, right, prefix, merged);
        }
    }
    return merged;
}

vector<list<int>> representBst(TreeNode* root){
    // vector<list<int>> bstList = createList(root);
    return createList(root);
} 

int main(void){
    return 0;
}