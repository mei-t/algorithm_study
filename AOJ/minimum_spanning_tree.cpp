#include<iostream>
using namespace std;
#define MAX 100
#define INFTY 2001
#define WHITE 0
#define GRAY 1
#define BLACK 2

int M[MAX][MAX], d[MAX];
// int p[MAX]; // p[u]はuの親を記録しておく配列だが本文では使う必要ない

void prim(int n){
  int color[MAX], u;

  // 初期化
  for(int i=0; i<n; i++){
    color[i] = WHITE;
    d[i] = INFTY;
  }
  d[0] = 0;
  //p[0] = -1;

  while(true){
    int mincost = INFTY;
    for(int i=0; i<n; i++){
      if(color[i] != BLACK && d[i] < mincost){
        mincost = d[i];
        u = i;
      }
    }

    if(mincost == INFTY) break;

    color[u] = BLACK;

    // 次にTに含まれる可能性のあるノードに関して重みを記録する
    for(int v=0; v<n; v++){
      if(color[v] != BLACK && M[u][v] != INFTY){
        if(M[u][v] < d[v]){
          d[v] = M[u][v];
          //p[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
}

int main(void){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> M[i][j];
      if(M[i][j] == -1) M[i][j] = INFTY;
    }
  }

  prim(n);

  // 最小全域木の辺の重みの総和を計算
  int u = 0;
  int d_sum = 0;
  for(int i=0; i<n; i++){
    d_sum += d[i];
  }
  cout << d_sum << endl;
  return 0;
}
