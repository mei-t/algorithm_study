#include <iostream>
using namespace std;

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j=p; j<r; j++){
        if(A[j] <= x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

int main(void){
    int n;
    int A[100001];
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    
    int q = partition(A, 0, n-1);
    for(int i=0; i<n; i++){
        cout << (i ? " " : "") << (i==q ? "[" : "") << A[i] << (i==q ? "]" : "");
    }
    cout << endl;
    return 0;
}