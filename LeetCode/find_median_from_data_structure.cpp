#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    // MedianFinder(){}
    
    void addNum(int num);
    
    double findMedian();

private:
    vector<int> v;
};

void MedianFinder::addNum(int num){
    // if(v.empty()){
    //     v.push_back(num);
    //     return;
    // }
    size_t left = 0;
    size_t right = v.size();
    while(left < right){
        int mid = (left + right) / 2;
        if(v[mid] > num){
            right = mid;
        }else if(v[mid] < num){
            left = mid + 1;
        }else{
            left = mid;
            right = mid;
        }
    }
    v.insert(v.begin() + left, num);
    return;
}

double MedianFinder::findMedian(){
    if(v.empty()){
        return 0;
    }
    int mid = v.size() / 2;
    if(v.size() % 2){
        return v[mid];
    }
    return static_cast<double>(v[mid - 1] + v[mid]) / 2;
}

class MedianFinder2 {
public:
    // MedianFinder(){}
    
    void addNum(int num);
    
    double findMedian();

private:
    priority_queue<int> minQueue;
    priority_queue<int, vector<int>, greater<int>> maxQueue;
};

void MedianFinder2::addNum(int num){
    minQueue.push(num);
    maxQueue.push(minQueue.top());
    minQueue.pop();
    if(minQueue.size() < maxQueue.size()){
        minQueue.push(maxQueue.top());
        maxQueue.pop();
    }
}

double MedianFinder2::findMedian(){
    if(minQueue.empty()){
        return 0;
    }else if(maxQueue.empty()){
        return minQueue.top();
    }
    if(minQueue.size() == maxQueue.size()){
        return static_cast<double>(minQueue.top() + maxQueue.top()) / 2;
    }
    return minQueue.top();
}


int main(void){
    return 0;
}