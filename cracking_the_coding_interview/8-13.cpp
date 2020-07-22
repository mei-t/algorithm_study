#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Box {
    int wi, hi, di;
};

int findHighest(const vector<Box>& boxes){
    auto cmp = [](Box left, Box right) {
        if (left.hi != right.hi)
            return left.hi < right.hi;
        if (left.wi != right.wi)
            return left.wi < right.wi;
        return left.di < right.di;
    };
    priority_queue<Box, vector<Box>, decltype(cmp)> q(cmp);
    for(Box box: boxes)
        q.push(box);
    
    vector<pair<int, Box>> heights;
    heights.push_back(pair<int, Box>(0, Box{INT_MAX, INT_MAX, INT_MAX}));
    while(!q.empty()){
        Box box = q.top();
        q.pop();
        for(auto h: heights){
            if(h.second.wi > box.wi && h.second.di > box.di)
                heights.push_back(pair<int, Box>(h.first + box.hi, box));
        }
    }

    int ans = 0;
    for(auto h: heights){
        if(ans < h.first)
            ans = h.first;
    }
    return ans;
}

int main(void){
    Box box1 = {1, 1, 1};
    Box box2 = {1, 5, 1};
    Box box3 = {3, 2, 3};
    Box box4 = {3, 3, 2};
    Box box5 = {2, 3, 3};
    vector<Box> input = {box1, box2, box3, box4, box5};
    cout << findHighest(input) << endl;;
    return 0;
}