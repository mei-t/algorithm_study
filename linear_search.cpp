#include <iostream>
using namespace std;

int LinearSearch(int S[], int n, int t){
    S[n] = t;
    int i = 0;
    while(S[i] != S[n]) i++;
    return (i != n);
}

int main(void){
    int n, q, t;
    int c = 0;
    cin >> n;
    int S[n];
    for(int i = 0; i < n; i++){
        cin >> S[i];
    }
    cin >> q;
    int same_number[q];
    bool second_time;
    for(int i = 0; i < q; i++){
        cin >> t;
        second_time = false;
        for(int j = 0; j < c; j++){
            if(same_number[j] == t) second_time = true;
        }
        if(LinearSearch(S, n, t) && !second_time){
            same_number[c] = t;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}