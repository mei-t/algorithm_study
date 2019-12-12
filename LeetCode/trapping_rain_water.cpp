#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 28分15秒

// 失敗
class Solution {
public:
    int trap(const vector<int>& height);
private:
    struct TWD{
        size_t start;
        size_t end;
    };
    vector<TWD*> findTWD(const vector<int>& height);
    int computeWaterVolume(const vector<int>& height, const vector<TWD*>& trapWaterData);
};

int Solution::trap(const vector<int>& height){
    if(height.empty()){
        return 0;
    }
    vector<TWD*> trapData = findTWD(height);
    return computeWaterVolume(height, trapData);
}

vector<Solution::TWD*> Solution::findTWD(const vector<int>& height){
    bool isTrap = false;
    bool isBottomFound = false;
    size_t start, end;
    vector<TWD*> v;
    vector<TWD*> tmp;
    for(size_t i = 0; i < height.size() - 1; i++){
        if(isTrap){
            if(height[i] >= height[start]){
                TWD* twd = new TWD{start, i};
                v.push_back(twd);
                isTrap = false;
                isBottomFound = false;
            }else if(!isBottomFound && height[i] < height[i + 1]){
                cout << "i = " << i << ", height[i] = " << height[i] << ", height[i + 1] = " << height[i + 1] << endl;
                // end = height[end] > height[i + 1] ? end : i + 1;
                end = i + 1;
                isBottomFound = true;
            }else if(isBottomFound && height[end] <= height[i]){
                end = i;
            }
        }
        if(!isTrap && height[i] > height[i + 1]){
            start = i;
            end = i + 1;
            isTrap = true;
        }
    }
    if(isTrap && isBottomFound){
        end = height[end] <= height[height.size() - 1] ? height.size() - 1 : end;
        TWD* twd = new TWD{start, end};
        v.push_back(twd);
    }
    return v;
}

int Solution::computeWaterVolume(const vector<int>& height, const vector<TWD*>& trapWaterData){
    int waterVolume = 0;
    for(TWD* twd: trapWaterData){
        int h = min(height[twd->start], height[twd->end]);
        cout << "start = " << twd->start << ", end = " << twd->end << ", height = " << h << endl;
        for(int i = twd->start + 1; i < twd->end; i++){
            waterVolume += max(h - height[i], 0);
        }
    }
    return waterVolume;
}

class Solution2 {
public:
    int trap(const vector<int>& height){
        if(height.size() < 3){
            return 0;
        }
        auto cmp = [](int left, int right, const vector<int>& height) {
            // return height[left] < height[right];
            if(height[left] == height[right]){
                return abs(static_cast<int>(height.size()) - left) < abs(static_cast<int>(height.size()) - right);
            }else{
                return height[left] < height[right];
            }
        }; 
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        if(height[0] > height[1]){
            pq.push(0);
        }
        for(int i=1; i<height.size() - 1; i++){
            if(height[i - 1] <= height[i] && height[i] >= height[i + 1]){
                pq.push(i);
            }
        }
        if(pq.size() < 2){
            return 0;
        }
        int start = pq.top();
        int end = start;
        int waterVolume = 0;
        pq.pop();
        while(!pq.empty() && (start > 0 || end < height.size() - 1)){
            int j = pq.top();
            pq.pop();
            if(j < start){
                int h = height[j];
                for(int k = j + 1; k < start; k++){
                    waterVolume += h - height[k];
                }
                start = j;
            }
            if(j > end){
                int h = height[j];
                for(int k = end + 1; k < j; k++){
                    waterVolume += h - height[k];
                }
                end = j;
            }
        }
        return waterVolume;
    }
};


int main(void){
    return 0;
}