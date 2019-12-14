#include <iostream>
#include <vector>
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

int main(void){
    return 0;
}