#include <iostream>
using namespace std;
#define MAX 26
#define NIL -1

int D[MAX];

struct Node{
  int parent, left, right;
};

struct Node T[MAX];

void setDepth(int u, int p){
  D[u] = p;
  if(T[u].left != NIL) setDepth(T[u].left, p+1);
  if(T[u].right != NIL) setDepth(T[u].right, p+1);
}

int setHeight(int H[], int u){
  int h1 = 0, h2 = 0;
  if(T[u].right != NIL) h1 = setHeight(H, T[u].right) + 1;
  if(T[u].left != NIL) h2 = setHeight(H, T[u].left) + 1;
  return H[u] = ((h1 > h2) ? h1 : h2);
}

void print(int H[], int n){
  for(int i=0; i<n; i++){
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "sibling = ";
    if(T[i].parent == NIL) cout << NIL << ", ";
    else if(T[T[i].parent].right != i) cout << T[T[i].parent].right << ", ";
    else cout << T[T[i].parent].left << ", ";
    cout << "degree = ";
    if(T[i].left != NIL && T[i].right != NIL) cout << "2, ";
    else if(T[i].left == NIL && T[i].right == NIL) cout << "0, ";
    else cout << "1, ";
    cout << "depth = " << D[i] << ", ";
    cout << "height = " << H[i] << ", ";
    if(T[i].parent == NIL) cout << "root" << endl;
    else if(T[i].left == NIL && T[i].right == NIL) cout << "leaf" << endl;
    else cout << "internal node" << endl;
  }
  return;
}

int main(void){
  int n, id, l, r, root;
  int H[MAX];
  cin >> n;
  // 初期化
  for(int i=0; i<n; i++){
    T[i].parent = T[i].left = T[i].right = NIL;
  }

  for(int i=0; i<n; i++){
    cin >> id >> l >> r;
    T[id].left = l;
    T[id].right = r;
    T[l].parent = id;
    T[r].parent = id;
  }

  // rootを見つける
  for(int i=0; i<n; i++){
    if(T[i].parent == NIL) root = i;
  }

  setDepth(root, 0);
  setHeight(H, root);

  print(H, n);
  return 0;
}
