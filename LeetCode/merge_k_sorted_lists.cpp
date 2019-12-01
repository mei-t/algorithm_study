#include <iostream>
#include <vector>
// #include <algorithm>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:  
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        int minIndex = -1;
        int min = INT_MAX;
        for(int i=0; i<lists.size(); i++){
            if(!lists[i]){
                continue;
            }
            if(lists[i]->val < min){
                minIndex = i;
                min = lists[i]->val;
            }
        }
        if(minIndex == -1){
            return nullptr;
        }
        ListNode* node = lists[minIndex];
        lists[minIndex] = node->next;
        node->next = mergeKLists(lists);
        return node;
    }
};

class Solution2 {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists);

    ListNode* mergeKLists(priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>& lists);

private:
    function<bool(ListNode*, ListNode*)> cmp = [](ListNode* node1, ListNode* node2){
        if(!node1){
            return true;
        }else if(!node2){
            return false;
        }else{
            return node1->val > node2->val;
        }
    };
};

ListNode* Solution2::mergeKLists(vector<ListNode*>& lists) { 
    if(lists.empty()){
        return nullptr;
    } else if(lists.size() == 1){
        return lists[0];
    }

    // struct{
    //     bool operator() (ListNode* node1, ListNode* node2){
    //         if(!node1){
    //             return false;
    //         }else if(!node2){
    //             return true;
    //         }else{
    //             return node1->val < node2->val;
    //         }
    //     }
    // } nodeLess;
    // sort(lists.begin(), lists.end(), nodeLess);

    
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
    for(ListNode* node: lists){
        q.push(node);
    }
    ListNode* node = mergeKLists(q);
    return node;
}

ListNode* Solution2::mergeKLists(priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>& lists) { 
    if(!lists.top()){
        return nullptr;
    }

    ListNode* node = lists.top();
    lists.pop();
    lists.push(node->next);
    node->next = mergeKLists(lists);
    return node;
}

int main(void){
    return 0;
}