#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int masseur(const vector<int>& times, size_t i, unordered_map<int, int>* memo){
    if(i >= times.size()){
        return 0;
    }else if(memo->find(i) != memo->end()){
        return (*memo)[i];
    }

    int timeSum = max(times[i] + masseur(times, i + 2, memo), masseur(times, i + 1, memo));
    memo->insert({i, timeSum});
    return timeSum;
}

int masseur(const vector<int>& times){
    unordered_map<int, int> memo;
    return masseur(times, 0, &memo);
}

int masseur2(const vector<int>& times){
    int onePrev = 0;
    int twoPrev = 0;
    for(int i = times.size() - 1; i >= 0; i--){
        int current = max(onePrev, twoPrev + times[i]);
        twoPrev = onePrev;
        onePrev = current;
    }
    return onePrev;
}

int main(void){
    vector<int> times = {30, 15, 60, 75, 45, 15, 15, 45};
    cout << masseur(times) << endl;
    cout << masseur2(times) << endl;
    return 0;
}