#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Box {
    int w, h, d;
};

int findHighest(const vector<Box>& boxes){
    auto cmp = [](Box left, Box right) {
        if (left.h != right.h)
            return left.h < right.h;
        if (left.w != right.w)
            return left.w < right.w;
        return left.d < right.d;
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
            if(h.second.w > box.w && h.second.d > box.d)
                heights.push_back(pair<int, Box>(h.first + box.h, box));
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