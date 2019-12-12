#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

struct Life{
    int birth;
    int death;
};

int findYear(const vector<Life>& lifes){
    auto cmp = [](pair<int, bitset<1>> left, pair<int, bitset<1>> right){
        if(left.first == right.first){
            return left.second == 1;
        }else{
            return left.first > right.first;
        }
    };
    priority_queue<pair<int, bitset<1>>, vector<pair<int, bitset<1>>>, decltype(cmp)> pq(cmp);
    for(const Life& life: lifes){
        pq.push(make_pair(life.birth, bitset<1>(0)));
        pq.push(make_pair(life.death, bitset<1>(1)));
    }

    int max = 0;
    int tmp = 0;
    int ans;
    while(!pq.empty()){
        int year = pq.top().first;
        while(!pq.empty() && pq.top().first == year && pq.top().second == 0){
            tmp++;
            pq.pop();
        }
        if(max < tmp){
            max = tmp;
            ans = year;
        }
        while(!pq.empty() && pq.top().first == year){
            tmp--;
            pq.pop();
        }
    }
    return ans;
}

int main(void){
    vector<Life> lifes = {
        {1920, 1950},
        {1900, 1925},
        {1925, 2000}
    };
    cout << findYear(lifes) << endl;
    return 0;
}