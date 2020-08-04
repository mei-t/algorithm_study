#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int>& prerequisite: prerequisites) {
            int cur = prerequisite[0];
            int next = prerequisite[1];
            if(numMap.find(cur) == numMap.end())
                numMap.insert({cur, vector<int>()});
            if(indeg.find(next) == indeg.end())
                indeg.insert({next, 0});
            numMap[cur].push_back(next);
            indeg[next]++;
        }
        for(auto it: numMap) {
            int num = it.first;
            if(indeg.find(num) == indeg.end())
                s.push(num);
        }
        while(!s.empty()) {
            int num = s.top();
            s.pop();
            for(int next: numMap[num]) {
                indeg[next]--;
                if(indeg[next] == 0)
                    s.push(next);
            }
            numMap.erase(num);
        }
        return numMap.empty();
    }
private:
    unordered_map<int, vector<int>> numMap;
    unordered_map<int, int> indeg;
    stack<int> s;
};


int main(void){
    Solution sol;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {0, 1}
    };
    bool canFinish = sol.canFinish(2, prerequisites);
    cout << (canFinish ? "true" : "false") << endl;
    return 0;
}