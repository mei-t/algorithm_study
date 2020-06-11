#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// struct Node{
//     int val;
//     Node* prev;
// };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int>& prerequisite: prerequisites){
            for(int i = 0; i < prerequisite.size() - 1; i++){
                int cur = prerequisite[i];
                if(numMap.find(cur) == numMap.end()){
                    numMap.insert({cur, vector<int>()});
                }
                numMap[cur].push_back(prerequisite[i + 1]);
            }
        }
        for(auto it: numMap){
            if(!search(it.first, unordered_set<int>()))
                return false;
        }
        return true;
    }
private:
    unordered_map<int, vector<int>> numMap;
    bool search(int num, unordered_set<int> numSet){
        numSet.insert(num);
        for(int next: numMap[num]){
            if(numSet.find(next) != numSet.end() || !search(next, numSet))
                return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         Node* prev = nullptr;
//         unordered_map<int, Node*> nodeMap;
//         for(vector<int>& prerequisite: prerequisites){
//             unordered_set<int> numSet;
//             for(int i = prerequisite.size() - 1; i >= 0; i--){
//                 int num = prerequisite[i];
//                 if(nodeMap.find())
//                 Node* node(num, prev);
//                 nodeMap.insert({num, node});
//                 prev = current;
//                 numSet.insert(num);
//             }
//         }
//     }
// };

int main(void){
    return 0;
}