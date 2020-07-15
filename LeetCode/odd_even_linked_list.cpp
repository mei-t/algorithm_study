#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        ListNode* even = head;
        ListNode* odd = head->next;
        ListNode* odd_first = odd;
        while(odd && odd->next){
            even->next = odd->next;
            odd->next = odd->next->next;
            even = even->next;
            odd = odd->next;
        }
        even->next = odd_first;
        return head;
    }
};

ListNode* createLinkedList(const vector<int>& nums, int index) {
    if(nums.size() == index)
        return nullptr;
    ListNode* node = new ListNode(nums[index]);
    node->next = createLinkedList(nums, ++index);
    return node;
}

ListNode* createLinkedList(const vector<int>& nums) {
    return createLinkedList(nums, 0);
}

int main(void){
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* root = createLinkedList(nums);
    Solution sol;
    ListNode* node = sol.oddEvenList(root);
    while(node){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}