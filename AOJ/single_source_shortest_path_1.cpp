#include <iostream>
using namespace std;
#define MAX 100
#define INFTY 10000001
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define DEFLT 0 // 初期値

int M[MAX][MAX], d[MAX];

void dijkstra(int n){
  int mincost, u, color[n], p[n];
  for(int i=0; i<n; i++){
    color[i] = WHITE;
    d[i] = INFTY;
  }

  d[DEFLT] = 0;
  p[DEFLT] = -1;

  while(true){
    mincost = INFTY;
    for(int i=0; i<n; i++){
      if(color[i] != BLACK && d[i] < mincost){
        mincost = d[i];
        u = i;
      }
    }

    if(mincost == INFTY) break;

    color[u] = BLACK;

    for(int v=0; v<n; v++){
      if(color[v] != BLACK && M[u][v] < INFTY){
        if(d[u] + M[u][v] < d[v]){
          d[v] = d[u] + M[u][v];
          p[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
}

int main(void){
  int n, u, k, v, c;
  cin >> n;

  for(u=0; u<MAX; u++){
    for(v=0; v<MAX; v++){
      M[u][v] = INFTY;
    }
  }

  for(int i=0; i<n; i++){
    cin >> u >> k;
    for(int j=0; j<k; j++){
      cin >> v >> c;
      M[u][v] = c;
    }
  }

  dijkstra(n);

  for(int i=0; i<n; i++){
    cout << i << " " << d[i] << endl;;
  }
  return 0;
}
