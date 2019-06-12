#include <stdio.h>
#define INFTY 1000000001

int comp_count;

void merge(int S[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i] = S[left + i];
    }
    for(int i=0; i<n2; i++){
        R[i] = S[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;

    int i=0;
    int j=0;
    for(int k=left; k<right; k++){
        if(L[i] <= R[j]){
            S[k] = L[i];
            i++;
        }else{
            S[k] = R[j];
            j++;
        }
    }
    comp_count += right - left;
}

void mergeSort(int S[], int left, int right){
    if(left + 1 < right){
         int mid = (left + right) / 2;
        mergeSort(S, left, mid);
        mergeSort(S, mid, right);
        merge(S, left, mid, right);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    int S[n];
    for(int i=0; i<n; i++){
        scanf("%d", &S[i]);
    }
    comp_count = 0;

    mergeSort(S, 0, n);
    for(int i=0; i<n; i++){
        printf("%d", S[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
    printf("%d\n", comp_count);
    return 0;
}