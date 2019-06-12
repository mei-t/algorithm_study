#include <iostream>
using namespace std;
#define MAX 101

int main(void){
  int n, u, k, v, Adj[MAX][MAX];
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> u >> k;
    for(int j=1; j<=n; j++){
      Adj[i][j] = 0;
    }
    for(int j=0; j<k; j++){
      cin >> v;
      Adj[u][v] = 1;
    }
    for(int j=1; j<=n; j++){
      if(j-1) cout << " ";
      cout << Adj[i][j];
    }
    cout << endl;
  }

  return 0;
}
