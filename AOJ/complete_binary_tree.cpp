#include <iostream>
using namespace std;
#define MAX 251

void print(){
}

int main(void){
  int n, H[MAX];
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> H[i];
  }

  for(int i=1; i<=n; i++){
    cout << "node " << i << ": ";
    cout << "key = " << H[i] << ", ";
    if(i != 1) cout << "parent key = " << H[i/2] << ", ";
    if(i * 2 < n + 1) cout << "left key = " << H[i * 2] << ", ";
    if(i * 2 + 1 < n + 1) cout << "right key = " << H[i * 2 + 1] << ", ";
    cout << endl;
  }
  return 0;
}
