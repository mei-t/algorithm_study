#include <iostream>
#include <unordered_map>
using namespace std;

enum Coin {TwentyFive, Ten, Five, One, Zero};

int coinToNum(Coin coin) {
    int num;
    switch(coin) {
        case TwentyFive:
            num = 25;
            break;
        case Ten:
            num = 10;
            break;
        case Five:
            num = 5;
            break;
        case One:
            num = 1;
            break;
        default:
            num = 0;
    }
    return num;
}

Coin nextBiggest(Coin coin) {
    Coin next;
    switch(coin) {
        case TwentyFive:
            next = Ten;
            break;
        case Ten:
            next = Five;
            break;
        case Five:
            next = One;
            break;
        default:
            next = Zero;
    }
    return next;
}

int numberOfCoin(int n, Coin coin, unordered_map<int, int>& numMap) {
    if(n == 0)
        return 1;
    if(coin == Zero)
        return 0;
    if(numMap.find(n * 10 + coin) != numMap.end())
        return numMap[n * 10 + coin];
    int x = coinToNum(coin);
    int ans = 0;
    if(n >= x)
        ans += numberOfCoin(n - x, coin, numMap);
    ans += numberOfCoin(n, nextBiggest(coin), numMap);
    numMap.insert({n * 10 + coin, ans});
    return ans;
}

int numberOfCoin(int n) {
    unordered_map<int, int> numMap;
    return numberOfCoin(n, TwentyFive, numMap);
}

int main(void){
    cout << numberOfCoin(100) << endl;
    return 0;
}