#include <iostream>
using namespace std;

#define MAX 100
#define Q_MAX 50 // キューの中身が50を越える時はhead=tailになってうまくいかない。Q_MAXを100に増やせばこの心配はない。
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFTY -1

// d[i]は始点sから各頂点iまでの最短距離
int M[MAX][MAX], color[MAX], d[MAX], Q[Q_MAX], head, tail;

void enqueue(int x){
  Q[tail] = x;
  if(tail + 1 == Q_MAX) tail = 0;
  else tail++;
}

int dequeue(){
  int x = Q[head];
  if(head + 1 == Q_MAX) head = 0;
  else head++;
  return x;
}

// 頂点番号は0-オリジン
void bfs(int n, int s){
  // 初期化
  head = 0;
  tail = 0;
  for(int i=0; i<n; i++){
    color[i] = WHITE;
    d[i] = INFTY;
  }

  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);

  int u;
  while(head != tail){
    u = dequeue();
    for(int v=0; v<n; v++){
      if(M[u][v] && color[v] == WHITE){
        color[v] = GRAY;
        d[v] = d[u] + 1;
        enqueue(v);
      } 
    }
    color[u] = BLACK;
  }
}

int main(void){
  int n, u, k, v;
  cin >> n;

  // M[][]の初期化
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      M[i][j] = 0;
    }
  }

  for(int i=0; i<n; i++){
    cin >> u >> k;
    u--; // 頂点番号を0-オリジンにする。
    for(int j =0; j<k; j++){
      cin >> v;
      M[u][--v] = 1; // 頂点番号を0-オリジンにする。
    } 
  }

  bfs(n, 0);
  for(int i=0; i<n; i++){
    cout << i+1 << " " << d[i] << endl;
  }
  return 0;
}
