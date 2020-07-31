#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), intervalsLess);

        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size()){
            int max = intervals[i][1];
            int j = i + 1;
            while(j < intervals.size() && intervals[j][0] <= max){
                if(max < intervals[j][1])
                    max = intervals[j][1];
                j++;
            }
            res.push_back({intervals[i][0], max});
            i = j;
        }
        return res;
    }
private:
    struct{
        bool operator()(vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        }
    } intervalsLess;
};

int main(void){
    vector<vector<int>> input1 = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };
    vector<vector<int>> input2 = {
        {1, 4},
        {4, 5}
    };
    vector<vector<int>> input3 = {
        {1, 4},
        {0, 2},
        {3, 5}
    };
    Solution sol;
    vector<vector<int>> res1 = sol.merge(input1);
    for(auto& interval: res1){
        cout << interval[0] << " " << interval[1] << endl;
    }
    cout << "--------------" << endl;
    vector<vector<int>> res2 = sol.merge(input2);
    for(auto& interval: res2){
        cout << interval[0] << " " << interval[1] << endl;
    }
    cout << "--------------" << endl;
    vector<vector<int>> res3 = sol.merge(input3);
    for(auto& interval: res3){
        cout << interval[0] << " " << interval[1] << endl;
    }
    return 0;
}