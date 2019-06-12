#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 100000

struct card{
    char chara;
    int num;
    int index;
};

int partition(card A[], int p, int r){
    int x = A[r].num;
    int i = p-1;
    for(int j=p; j<r; j++){
        if(A[j].num <= x){
            i = i+1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(card A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

void isStable(card A[], int n){
    int x;
    for(int i=0; i<n; i++){
        if(A[i].num == A[i+1].num && A[i].index > A[i+1].index){
            printf("Not stable\n");
            return;
        }
    }
    printf("Stable\n");
    return;
}

int main(void){
    int n;
    card A[MAX];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s %d", &A[i].chara, &A[i].num);
        A[i].index = i;
    }

    quickSort(A, 0, n-1);
    isStable(A, n);
    for(int i=0; i<n; i++){
        printf("%c %d\n", A[i].chara, A[i].num);
    }
    return 0;
}