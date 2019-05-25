#include <iostream>
using namespace std;
#define MAX 101
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, t, top, color[MAX], M[MAX][MAX], S[MAX], d[MAX], f[MAX];

int next(int u){
  for(int i=1; i<=n; i++){
    if(M[u][i] == 1 && color[i] == WHITE){
      return i;
    }
  }
  return NIL;
}

void dfs(int u){
  int v;
  S[++top] = u;
  color[u] = GRAY;
  d[u] = ++t;

  while(top > 0){
    u = S[top];
    v = next(u);
    if(v != NIL){
      color[v] = GRAY;
      d[v] = ++t;
      S[++top] = v;
    }else{
      top--;
      color[u] = BLACK;
      f[u] = ++t;
    }
  }
}

void dfs_init(){
  for(int i=0; i<MAX; i++){
    color[i] = WHITE;
  }

  t = 0;
  top = 0;
}

int main(void){
  int u[MAX], k, m;
  cin >> n;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      M[i][j] = 0;
    }
  }

  for(int i=0; i<n; i++){
    cin >> u[i] >> k;
    for(int j=0; j<k; j++){
      cin >> m;
      M[u[i]][m] = 1;
    }
  }

  dfs_init();
  for(int i=0; i<n; i++){
    if(d[u[i]] == 0) dfs(u[i]);
  }

  for(int i=0; i<n; i++){
    cout << u[i] << " " << d[u[i]] << " " << f[u[i]] << endl; 
  }
  return 0;
}
