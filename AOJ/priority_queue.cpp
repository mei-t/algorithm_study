#include <iostream>
#include <string>
using namespace std;
#define MAX 2000000
#define INFTY (1<<30)

int H, A[MAX];

void heapIncreaseKey(int key){
  int i, tmp;
  i = H;
  if(key < A[i]){
    cout << "ERROR: the new key is too small." << endl;
    return;
  }
  A[i] = key;
  while(i > 1 && A[i/2] < A[i]){
    tmp = A[i];
    A[i] = A[i/2];
    A[i/2] = tmp;
    i /= 2;
  }
}

void insert(int key){
  H++;
  A[H] = -1 * INFTY;
  heapIncreaseKey(key);
}

void maxHeapify(int i){
  int l, r, largest, tmp;
  l = i * 2;
  r = i * 2 + 1;

  // i番目のノードと左の子、右の子の中で最大のノードを選ぶ。
  if(H >= l && A[l] > A[i]) largest = l;
  else largest = i;
  if(H >= r && A[r] > A[largest]) largest = r;

  if(i != largest){
    tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;
    maxHeapify(largest);
  }
}

int heapExtractMax(){
  if(H < 1){
    cout << "ERROR: Overflow." << endl;
    return -1 * INFTY;
  }

  int max = A[1];
  A[1] = A[H];
  H--;
  maxHeapify(1);

  return max;
}

int main(void){
  int key, max;
  string order;
  bool is_end = false;
  H = 0;

  while(!is_end){
    cin >> order;
    if(order == "end"){
      is_end = true;
    }else if(order == "extract"){
      max = heapExtractMax();
      cout << max << endl;
    }else if(order == "insert"){
      cin >> key;
      insert(key);
    }
  }

  return 0;
}
