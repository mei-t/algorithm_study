#include <iostream>
#include <unordered_map>
using namespace std;

class RankOfNumber {
public:
    void track(int x);
    int getRankOfNumber(int x);
private:
    unordered_map<int, int> rankMap;
};

void RankOfNumber::track(int x){
    if(rankMap.find(x) == rankMap.end())
        rankMap.insert({x, 0});
    rankMap[x] = 0;
    for(auto& it: rankMap){
        if(it.first > x)
            it.second++;
        if(it.first < x)
            rankMap[x]++;
    }
}

int RankOfNumber::getRankOfNumber(int x){
    return rankMap[x];
}

int main(void){
    return 0;
}