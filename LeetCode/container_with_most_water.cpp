#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto cmp = [](pair<int, int> left, pair<int, int> right){
            return left.second < right.second;
        };
        priority_queue<int, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for(int i=0; i<height.size(); i++){
            q.push(make_pair(i, height[i]));
        }
        pair<int, int> highest = q.top();
        q.pop();
        pair<int, int> left = q.top();
        pair<int, int> right = q.top();
        highest.first < q.top().first ? left = highest : right = highest;
        q.pop();
        int max = (right.first - left.first) * min(left.second, right.second);
        while(!q.empty()){
            pair<int, int> next = q.top();
            q.pop();
            if(next.first < left.first){
                left = next;
            }else if(next.first > right.first){
                right = next;
            }else{
                continue;
            }
            int tmp = (right.first - left.first) * next.second;
            max = max < tmp ? tmp : max;
        }
        return max;
    }
};

int main(void){
    return 0;
}