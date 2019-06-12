#include <iostream>
using namespace std;
#define MAX 100000
#define NIL -1

struct Node { int parent, left, right; };
struct Node T[MAX];

int D[MAX];

// int getDepth(int u){
//   d = 0;
//   while(T[u].parent != NIL){
//     u = T[u].parent;
//     d++;
//   }
//   return d;
// }

void setDepth(int u, int p){
  D[u] = p;
  if(T[u].right != NIL){
    setDepth(T[u].right, p);
  }
  if(T[u].left != NIL){
    setDepth(T[u].left, p+1);
  }
}

void print(int n){
  bool isFirst;
  for(int i=0; i<n; i++){
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "depth = " << D[i] << ", ";
    if(T[i].parent == NIL) cout << "root, ";
    else if(T[i].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";
    cout << "[";
    int c = T[i].left;
    isFirst = true;
    while(c != NIL){
      if(!isFirst) cout << ", ";
      isFirst = false;
      cout << c;
      c = T[c].right;
    }
    cout << "]" << endl;
  }
  return;
}

int main(void){
  int n, id, k, c, left, root;
  cin >> n;
  for(int i=0; i<n; i++){
    T[i].parent = T[i].left = T[i].right = -1;
  }

  for(int i=0; i<n; i++){
    cin >> id >> k;
    for(int j=0; j<k; j++){
      cin >> c;
      T[c].parent = id;
      if(j) T[left].right = c;
      else T[id].left = c;
      left = c;
    }
  }

  for(int i=0; i<n; i++){
    if(T[i].parent == NIL) root = i;
  }

  setDepth(root, 0);
  print(n);
  return 0;
}
