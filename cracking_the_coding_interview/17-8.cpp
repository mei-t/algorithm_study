#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

// 23分38秒
vector<pair<int, int>> sortByHeight(const vector<pair<int, int>>& people){
    vector<pair<int, int>> heightOrder(people);
    struct{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    } heightLess;
    sort(heightOrder.begin(), heightOrder.end(), heightLess);
    return heightOrder;
}

vector<pair<int, int>> sortByWeight(const vector<pair<int, int>>& people){
    vector<pair<int, int>> weightOrder(people);
    struct{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    } weightLess;
    sort(weightOrder.begin(), weightOrder.end(), weightLess);
    return weightOrder;
}

int findTallestTower(const vector<pair<int, int>>& heightOrder, size_t heightI, const vector<pair<int, int>>& weightOrder, size_t weightI, int length, unordered_map<string, int>* lenMap){
    if(heightOrder.size() == heightI || weightOrder.size() == weightI){
        return length;
    }
    string index = to_string(heightI) + " " + to_string(weightI);
    auto it = lenMap->find(index);
    if(it != lenMap->end()){
        return it->second;
    }

    if(heightOrder[heightI].first != weightOrder[weightI].first || heightOrder[heightI].second != weightOrder[weightI].second){
        length = max(findTallestTower(heightOrder, heightI + 1, weightOrder, weightI, length, lenMap),findTallestTower(heightOrder, heightI, weightOrder, weightI + 1, length, lenMap));
    }else{
        length = findTallestTower(heightOrder, heightI + 1, weightOrder, weightI + 1, length + 1, lenMap);
    }
    lenMap->insert({index, length});
    return length;
}
int findTallestTower(const vector<pair<int, int>>& people){
    vector<pair<int, int>> heightOrder = sortByHeight(people);
    vector<pair<int, int>> weightOrder = sortByWeight(people);
    unordered_map<string, int> lenMap;
    return findTallestTower(heightOrder, 0, weightOrder, 0, 0, &lenMap);
}

int findTallestTower2(const vector<pair<int, int>>& people){
    vector<stack<pair<int, int>>> tallestArrays;
    int ans = 0;
    for(int i = 0; i < people.size(); i++){
        int tmpSize = 0;
        int tmp = 0;
        for(int j = 0; j < tallestArrays.size(); j++){
            if(people[i].first > tallestArrays[j].top().first && people[i].second > tallestArrays[j].top().second && tallestArrays[j].size() > tmpSize){
                tmpSize = tallestArrays[j].size();
                tmp = j;
            }
        }
        stack<pair<int, int>> tallestArray(tallestArrays[tmp]);
        tallestArray.push(people[i]);
        tallestArrays.push_back(tallestArray);
        if(tallestArray.size() > ans){
            ans = tallestArray.size();
        }
    }
    return ans;
}

int main(void){
    return 0;
}