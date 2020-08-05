#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, pair<int, vector<int>>> courseMap;
        for(vector<int>& prerequisite: prerequisites){
            if(courseMap.count(prerequisite[0]) == 0)
                courseMap.insert({prerequisite[0], pair<int, vector<int>>(0, vector<int>())});
            if(courseMap.count(prerequisite[1]) == 0)
                courseMap.insert({prerequisite[1], pair<int, vector<int>>(0, vector<int>())});
            courseMap[prerequisite[0]].first++;
            courseMap[prerequisite[1]].second.push_back(prerequisite[0]);
        }
        queue<int> q;
        for(auto it: courseMap){
            if(it.second.first == 0)
                q.push(it.first);
        }
        vector<int> res;
        while(!q.empty()){
            int num = q.front();
            res.push_back(num);
            q.pop();
            for(int next: courseMap[num].second){
                courseMap[next].first--;
                if(courseMap[next].first == 0)
                    q.push(next);
            }
        }
        for(int i = 0; i < numCourses; i++){
            if(courseMap.count(i) == 0)
                res.push_back(i);
        }
        if(res.size() < numCourses)
            return vector<int>();
        return res;
    }
};

void output(vector<int>& nums){
    for(int num : nums)
        cout << num << " ";
    cout << endl;
}

int main(void){
    vector<vector<int>> input1 = {{1, 0}};
    vector<vector<int>> input2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> input3 = {{1, 0}};

    Solution sol;
    vector<int> res1 = sol.findOrder(2, input1);
    output(res1);
    vector<int> res2 = sol.findOrder(4, input2);
    output(res2);
    vector<int> res3 = sol.findOrder(3, input3);
    output(res3);
    return 0;
}