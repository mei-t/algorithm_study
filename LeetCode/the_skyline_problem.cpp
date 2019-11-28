#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty()){
            return buildings;
        }
        size_t size = buildings.size();
        int cur = 0;
        int cur_X, cur_H;
        priority_queue<pair<int, int>> liveBuildings; // pair(H, R)
        vector<vector<int>> ans;
        while(cur < size || !liveBuildings.empty()){
            cur_X = liveBuildings.empty() ? buildings[cur][0] : liveBuildings.top().second;
            if(cur < size && (liveBuildings.empty() || cur_X >= buildings[cur][0])){
                cur_X = buildings[cur][0];
                while(cur < size && cur_X == buildings[cur][0]){
                    liveBuildings.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }else{
                while(!liveBuildings.empty() && liveBuildings.top().second <= cur_X){
                    liveBuildings.pop();
                }
            }
            cur_H = liveBuildings.empty() ? 0 : liveBuildings.top().first;
            if(ans.empty() || cur_H != ans.back()[1]){
                ans.push_back(vector<int>({cur_X, cur_H}));
            }
        }
        return ans;
    }
};
int main(void){
    return 0;
}