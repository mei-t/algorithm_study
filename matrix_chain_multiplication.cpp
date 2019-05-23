#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
#define INF 1<<30

int main(void){
  int n, p[MAX+1], m[MAX][MAX];
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> p[i] >> p[i+1];
  }

  for(int i=1; i<=n; i++){
    m[i][i] = 0;
  }

  for(int l=1; l<n; l++){ // iとjの差を1からn-1まで変化させる
    for(int i=1; i<=n-l; i++){
      int j = i + l; // l-1がiとjの差
      m[i][j] = INF;
      for(int k=i; k<j; k++){
        m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]);
      }
    }
  }
  cout << m[1][n] << endl;
  return 0;
}
