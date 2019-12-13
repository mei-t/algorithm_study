#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

struct Life{
    int birth;
    int death;
};

// TC: O(NlogN) (where N is the number of people(Life).)
// SC: O(N)
int findYear(const vector<Life>& lifes){
    auto cmp = [](int left, int right){ return left > right; };
    priority_queue<int, vector<int>, decltype(cmp)> birthQueue(cmp);
    priority_queue<int, vector<int>, decltype(cmp)> deathQueue(cmp);
    for(const Life& life: lifes){
        birthQueue.push(life.birth);
        deathQueue.push(life.death);
    }

    int max = 0;
    int tmp = 0;
    int ans;
    while(!deathQueue.empty()){
        int year;
        if(birthQueue.empty()){
            year = deathQueue.top();
        }else{
            year = min(birthQueue.top(), deathQueue.top());
        }
        while(!birthQueue.empty() && birthQueue.top() == year){
            tmp++;
            birthQueue.pop();
        }
        if(max < tmp){
            max = tmp;
            ans = year;
        }
        while(!deathQueue.empty() && deathQueue.top() == year){
            tmp--;
            deathQueue.pop();
        }
    }
    return ans;
}

// TC: O(N * M) (where N is the number of people(Life) and M is the range of years.)
// SC: O(1)
int findYear2(const vector<Life>& lifes, int start, int end){
    int max = 0;
    int tmp = 0;
    int ans;
    for(int i = start; i<= end; i++){
        for(const Life& life: lifes){
            if(life.birth <= i && i <= life.death){
                tmp++;
            }
        }
        if(max < tmp){
            max = tmp;
            ans = i;
        }
        tmp = 0;
    }
    return ans;
}

// TC: O(N + M) (where N is the number of people(Life) and M is the range of years.)
// SC: O(N)
int findYear3(const vector<Life>& lifes, int start, int end){
    vector<int> yearsPlus(end - start + 1, 0);
    vector<int> yearsMinus(end - start + 1, 0);
    for(const Life& life: lifes){
        yearsPlus[life.birth]++;
        yearsMinus[life.death]--;
    }

    int max = 0;
    int tmp = 0;
    int ans;
    for(int i = start; i <= end; i++){
        tmp += yearsPlus[i];
        if(tmp > max){
            max = tmp;
            ans = i;
        }
        tmp += yearsMinus[i];
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
    cout << findYear2(lifes, 1900, 2000) << endl;
    cout << findYear3(lifes, 1900, 2000) << endl;
    return 0;
}