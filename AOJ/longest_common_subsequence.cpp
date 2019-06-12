#include <iostream>
#include <string>
using namespace std;
#define MAX 1001

int lcs(string X, string Y){
  int c[MAX][MAX]; 
  int m = X.length();
  int n = Y.length();
  for(int i=0; i<m; i++){
    c[i][0] = 0;
  }
  for(int i=0; i<=n; i++){
    c[0][i] = 0;
  }
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(X[i-1] == Y[j-1]){
        c[i][j] = c[i-1][j-1] + 1;
      }else{
        c[i][j] = (c[i][j-1] > c[i-1][j] ? c[i][j-1] : c[i-1][j]);
      }
    }
  }
  return c[m][n];
}

int main(void){
  int q, l;
  string X, Y;
  cin >> q;
  for(int i=0; i<q; i++){
    cin >> X >> Y;
    l = lcs(X, Y);
    cout << l << endl;
  }
  return 0;
}
