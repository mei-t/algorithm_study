#include <iostream>
#include <vector>
using namespace std;

// 15分45秒
struct Node{
    int val;
    Node* next;
};

Node* sum(Node* node1, Node* node2){
    bool isFinished1 = !node1;
    bool isFinished2 = !node2;
    Node* ans;
    Node* current = ans;
    Node* prev;
    int advance = 0;
    while(!(isFinished1 && isFinished2)){
        int num1 = 0;
        int num2 = 0;
        if(!isFinished1){
            num1 = node1->val;
            if(node1->next){
                node1 = node1->next;
            }else{
                isFinished1 = true;
            }
        }
        if(!isFinished2){
            num2 = node2->val;
            if(node2->next){
                node2 = node2->next;
            }else{
                isFinished2 = true;
            }
        }

        int sum = num1 + num2 + advance;
        advance = sum / 10;
        sum %= 10;
        current = new Node;
        current->val = sum;
        if(prev){
            prev->next = current;
        }
        prev = current;
    }
    if(advance){
        current = new Node;
        current->val = advance;
        prev->next = current; // advance != 0の時while文の中が1回は実行されたということ。この時prevはnullではない
    }
    return ans;
}

Node* createInput(const vector<int>& nums){
    Node* first;
    Node* current = first;
    Node* prev;
    for(int num: nums){
        current = new Node;
        current->val = num;
        if(prev){
            prev->next = current;
        }
        prev = current;
    }
    return first;
}

void print(Node* node){
    cout << "print start" << endl;
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
    Node* node1 = createInput(nums1);
    Node* node2 = createInput(nums2);
    // print(node1);
    // print(node2);
    cout << "createInput sucesses." << endl;
    Node* ans = sum(node1, node2);
    cout << "aaa" << endl;
    // print(ans);
    return 0;
}