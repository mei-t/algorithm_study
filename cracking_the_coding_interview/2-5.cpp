#include <iostream>
#include <vector>
using namespace std;

// 15分45秒
struct Node{
    int val;
    Node* next;
};

Node* sumList(Node* node1, Node* node2, int advance){
    if(!(node1 && node2)){
        return nullptr;
    }

    int num1 = node1 ? node1->val : 0;
    int num2 = node2 ? node2->val : 0;
    int sum = num1 + num2 + advance;
    advance = sum / 10;
    sum %= 10;
    Node* current = new Node;
    current->val = sum;
    node1 = node1 ? node1->next : node1;
    node2 = node2 ? node2->next : node2;
    current->next = sumList(node1, node2, advance);
    return current;
}

Node* createNextNode(const vector<int>& nums, size_t pos){
    if(pos>= nums.size()){
        return nullptr;
    }
    Node* current = new Node;
    current->val = nums[pos];
    current->next = createNextNode(nums, pos+1);
    return current;
}

void print(Node* node){
    while(node){
        cout << node->val;
        if(node->next == nullptr){
            break;
        }
        node = node->next;
    }
    cout << endl;
}

int main(void){
    vector<int> nums1 = {7, 1, 6};
    vector<int> nums2 = {5, 9, 2};
    Node* node1 = createNextNode(nums1, 0);
    Node* node2 = createNextNode(nums2, 0);
    print(node1);
    print(node2);
    Node* ans = sumList(node1, node2, 0);
    print(ans);
    return 0;
}