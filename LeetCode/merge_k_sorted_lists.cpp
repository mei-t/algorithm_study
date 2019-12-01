#include <iostream>
#include <vector>
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

int main(void){
    return 0;
}