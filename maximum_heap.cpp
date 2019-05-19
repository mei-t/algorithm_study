#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 500000

int A[MAX];

void maxHeapify(int i, int H){
  int l, r, largest, tmp;
  l = i * 2;
  r = i * 2 + 1;

  if(l <= H && A[i] < A[l]) largest = l;
  else largest = i;
  if(r <= H && A[r] > A[largest]) largest = r;

  if(largest != i){
    tmp = A[largest]; A[largest] = A[i]; A[i] = tmp;
    maxHeapify(largest, H);
  }
}

void buildMaxHeap(int H){
  for(int i = H/2; i>0; i--) maxHeapify(i, H);
}

int main(void){
  int H;
  cin >> H;
  for(int i=1; i<=H; i++){
    cin >> A[i];
  }

  buildMaxHeap(H);
  for(int i=1; i<=H; i++) cout << " " << A[i];
  cout << endl;
  return 0;
}
