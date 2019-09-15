#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define N 

stack<int> s;

vector<vector<int> > NodeList = {{1, 2}, {0, 2}, {}};

bool isPath(int start, int last) {
    if (start == last) return true;
    s.push(start);
    while(s.empty()) {
        int node = s.top();
        s.pop();
        for (int nextNode : NodeList[node]) {
            if(nextNode == last) return true;
            s.push(nextNode);
        }
    }
    return false;
}

int main(void) {
    cout << isPath(0, 1) << endl;
    return 0;
}