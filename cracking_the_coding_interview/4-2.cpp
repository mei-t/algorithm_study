#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int key;
    double pos;
    int order;
};

void setNewTree(double pos, Node* parent, const vector<int>& list){
    const int size = list.size();
    int parentIndex = size * (parent -> pos);
    int currentIndex = size * pos;
    if(parentIndex == currentIndex){
        if(pos > parent -> pos){
            parent -> right = nullptr;
        }else{
            parent -> left = nullptr;
        }
        return;
    }

    int order = (parent -> order) + 1;
    Node* newNode = new Node();
    newNode -> key = list[currentIndex];
    newNode -> pos = pos;
    newNode -> parent = parent;
    newNode -> order = order;
    if(pos > parent -> pos){
        parent -> right = newNode;
    }else{
        parent -> left = newNode;
    }
    setNewTree(pos - 1/pow(2, order + 1), newNode, list);
    setNewTree(pos + 1/pow(2, order + 1), newNode, list);
}

Node* minTree(const vector<int>& list){
    const int size = list.size();
    Node* begin = new Node();
    double pos = 1/2;
    int order = 1;

    begin -> parent = nullptr;
    begin -> key = list[size * pos];
    begin -> pos = pos;
    begin -> order = order;

    setNewTree(pos - 1/pow(2, order + 1), begin, list);
    setNewTree(pos + 1/pow(2, order + 1), begin, list);

    return begin;
}

int main(void){
    return 0;
}