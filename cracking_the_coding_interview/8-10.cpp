#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int color;
    bool isEnd;
    Node* upperLeft;
    Node* upperRight;
    Node* lowerLeft;
    Node* lowerRight;
};

void fill(vector<vector<int>>& matrix, Node* node, int xStart, int xEnd, int yStart, int yEnd){
    if(!node)
        return;
    if(node->isEnd){
        for(int i = xStart; i < xEnd; i++){
            for(int j = yStart; j < yEnd; j++){
                matrix[i][j] = node->color;
            }
        }
        return;
    }
    fill(matrix, node->upperLeft, xStart, xEnd/2, yStart, yEnd/2);
    fill(matrix, node->upperRight, xEnd/2, xEnd, yStart, yEnd/2);
    fill(matrix, node->lowerLeft, xStart, xEnd/2, yEnd/2, yEnd);
    fill(matrix, node->upperLeft, xEnd/2, xEnd, yEnd/2, yEnd);
}

void fill(vector<vector<int>>& matrix, Node* root){
    if(matrix.empty())
        return;
    fill(matrix, root, 0, matrix[0].size(), 0, matrix.size());
    return;
}

int main(void){
    return 0;
}