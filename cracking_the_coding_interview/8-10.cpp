#include <iostream>
#include <vector>
using namespace std;
#define END -2
#define CON -1

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

    // fill(matrix, node->upperLeft, xStart, (xEnd + 1) / 2, yStart, (yEnd + 1) / 2);
    // fill(matrix, node->upperRight, (xEnd + 1) / 2, xEnd, yStart, (yEnd + 1) / 2);
    // fill(matrix, node->lowerLeft, xStart, (xEnd + 1) / 2, (yEnd + 1) / 2, yEnd);
    // fill(matrix, node->upperLeft, (xEnd + 1) / 2, xEnd, (yEnd + 1) / 2, yEnd);
}

void fill(vector<vector<int>>& matrix, Node* root){
    if(matrix.empty())
        return;
    fill(matrix, root, 0, matrix[0].size(), 0, matrix.size());
    return;
}

Node* makeNode(vector<int>& colors, int index){
    if(index >= colors.size())
        return nullptr;
    Node* node = new Node();
    if(colors[index] >= 0){
        node->color = colors[index];
        node->isEnd = true;
        return node;
    }
    index++;
    node->upperLeft = makeNode(colors, index * 4 - 3);
    node->lowerLeft = makeNode(colors, index * 4 - 2);
    node->lowerRight = makeNode(colors, index * 4 - 1);
    node->upperRight = makeNode(colors, index * 4);
    return node;
}

int main(void){
    // vector<int> colors = {CON, 0, CON, CON, CON, END, END, END, END, CON, 3, CON, 1, CON, CON, CON, 2, 0, CON, CON, CON, };
    vector<int> colors = {CON, 0, CON, 1, CON, END, END, END, END, 0, 1, 1, 1, END, END, END, END, 0, 1, 1, 1};
    Node* root = makeNode(colors, 0);
    vector<int> line(4, -1);
    vector<vector<int>> matrix(4, line);
    fill(matrix, root);
    for(vector<int>& line: matrix){
        for(int num: line){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}