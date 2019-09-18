#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
#define WHITE 0

stack<int> s;

vector<vector<int> > NodeList = {{1, 2}, {0, 2}, {}};

bool isPath(int start, int last) {
    if (start == last) return true;
    s.push(start);
    set<int> visited = { start };
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        for (int nextNode : NodeList[node]) {
            if(nextNode == last) return true;
            auto search = visited.find(nextNode);
            if(search == visited.end()) {
                s.push(nextNode);
                visited.insert(nextNode);
            }
        }
    }
    return false;
}

int main(void) {
    cout << isPath(0, 1) << endl;
    return 0;
}