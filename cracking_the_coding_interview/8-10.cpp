#include <iostream>
#include <vector>
using namespace std;
#define END -2
#define CON -1

enum Color {BLACK, WHITE, RED, BLUE, YELLOW, GREEN};

bool paintFill(vector<vector<Color>>& screen, unsigned int r, unsigned int c, Color origCol, Color newCol){
    if(r < 0 || r >= screen.size() || c < 0 || c >= screen[0].size())
        return false;
    if(screen[r][c] == origCol){
        screen[r][c] = newCol;
        paintFill(screen, r - 1, c, origCol, newCol);
        paintFill(screen, r, c - 1, origCol, newCol);
        paintFill(screen, r + 1, c, origCol, newCol);
        paintFill(screen, r, c + 1, origCol, newCol);
    }
    return true;
}

bool paintFill(vector<vector<Color>>& screen, unsigned int r, unsigned int c, Color color){
    if(screen[r][c] == color)
        return false;
    return paintFill(screen, r, c, screen[r][c], color);
}

// This solution does not satisfy the intent of the question 
// because I misunderstood the problem.
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
    fill(matrix, node->upperLeft, xStart, (xStart + xEnd) / 2, yStart, (yStart + yEnd) / 2);
    fill(matrix, node->lowerLeft, xStart, (xStart + xEnd) / 2, (yStart + yEnd) / 2, yEnd);
    fill(matrix, node->lowerRight, (xStart + xEnd) / 2, xEnd, (yStart + yEnd) / 2, yEnd);
    fill(matrix, node->upperRight, (xStart + xEnd) / 2, xEnd, yStart, (yStart + yEnd) / 2);
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
    vector<vector<Color>> screen = {
        {BLUE, BLUE, BLUE, WHITE, WHITE, WHITE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, WHITE, WHITE, WHITE, BLUE, BLUE},
        {BLACK, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
        {BLACK, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
        {BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
    };
    paintFill(screen, 0, 3, YELLOW);
    for(vector<Color>& line: screen) {
        for(Color col: line) {
            // cout << col << " ";
            switch (col) {
                case BLACK:
                    cout << "BLACK ";
                case WHITE:
                    cout << "WHITE ";
                case RED:
                    cout << "RED ";
                case BLUE:
                    cout << "BLUE ";
                case GREEN:
                    cout << "GREEN ";
                case YELLOW:
                    cout << "YELLOW ";
            }
        }
        cout << endl;
    }
    return 0;
}