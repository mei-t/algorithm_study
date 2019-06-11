#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define MAX 10000
#define INFTY 10000000
#define DEFLT 0
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
vector<pair<int, int> > adj[MAX];

void dijkstra(){
  int u, v, d[MAX], color[MAX];
  priority_queue<pair<int, int> > PQ; // uからvへの重みcとuに隣接する頂点の番号vのペア: pair<c, v*(-1)>

  for(int i=0; i<n; i++){
    color[i] = WHITE;
    d[i] = INFTY;
  }
  d[DEFLT] = 0;
  color[0] = GRAY;

  PQ.push(make_pair(0, DEFLT));

  while(!PQ.empty()){
    pair<int, int> f = PQ.top();
    PQ.pop();
    u = f.second;
    color[u] = BLACK;
    if(d[u] < f.first * (-1)) continue;

    for(int i=0; i<adj[u].size(); i++){
      v = adj[u][i].second;
      if(color[v] != BLACK && d[u] + adj[u][i].first < d[v]){
        //cout << "u=" << u << ", v=" << v << ", d[u]=" << d[u] << ", d[v]=" << d[v] << "adj[u][i].first=" << adj[u][i].first << endl;
        d[v] = d[u] + adj[u][i].first;
        color[v] = GRAY;
        PQ.push(make_pair(d[v] * (-1), v));
      }
    }
  }

  for(int i=0; i<n; i++){
    cout << i << " " << d[i] << endl;
  }
}

int main(void){
  int u, k, v, c;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> u >> k;
    for(int j=0; j<k; j++){
      cin >> v >> c;
      adj[u].push_back(make_pair(c, v));
    }
  }

  dijkstra();
  return 0;
}
