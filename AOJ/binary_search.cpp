#include <stdio.h>

bool BinarySearch(int S[], int n, int t){
    int left = 0;
    int right = n;
    int mid;
    int i = 0;
    while(left < right){
        mid = (left + right) / 2;
        if(t == S[mid]) return true;
        else if(t < S[mid]) right = mid;
        else left = mid + 1;
    }

    return false;
}

int main (void){
    int n, q, t;
    int c = 0;
    bool second_time;

    scanf("%d", &n);
    int S[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    int same_number[q];
    for(int i = 0; i < q; i++){
        scanf("%d", &t);
        second_time = false;
        // for(int j = 0; j < c; j++){
        //     if(same_number[j] == t) second_time = true;
        // }
        if(BinarySearch(S, n, t)){// && !second_time){
            same_number[c] = t;
            c++;
            printf("%d\n", t);
        }
    }
    printf("%d\n", c);
    return 0;
}