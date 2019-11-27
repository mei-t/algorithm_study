#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int computeGcd(int x, int y){
    if(y == 0){
        return x;
    }
    return computeGcd(y, x % y);
}

int main(void){
    int A, B;
    cin >> A >> B;
    int gcd = computeGcd(A, B);
    int count = 0;
    int i = 2;
    int n = gcd;
    for(long i = 2; i*i <= n; i++){
        if(n % i){
            continue;
        }
        count++;
        while(n % i == 0){
            n /= i;
        }
        i++;
    }
    if(n != 1){
        count++;
    }
    count++;
    cout << count << endl;
    return 0;
}