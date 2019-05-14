// コメントアウトしたisFirstを用いれば、最初のスペースをなくすことができる
#include <stdio.h>
#define MAX 26
#define NIL -1

// bool isFirst;

struct Node{
    int parent, left, right;
};

struct Node T[MAX];

void prePerse(int u){
    if(u == NIL) return;
    // if(!isFirst) 
    printf(" ");
    // isFirst = false;
    printf("%d", u);
    prePerse(T[u].left);
    prePerse(T[u].right);
}

void inPerse(int u){
    if(u == NIL) return;
    inPerse(T[u].left);
    // if(!isFirst) 
    printf(" ");
    // isFirst = false;
    printf("%d", u);
    inPerse(T[u].right);
}

void postPerse(int u){
    if(u == NIL) return;
    postPerse(T[u].left);
    postPerse(T[u].right);
    // if(!isFirst) 
    printf(" ");
    // isFirst = false;
    printf("%d", u);
}

int main(void){
    int n, id, l, r, root;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    for(int i=0; i<n; i++){
        scanf("%d %d %d", &id, &l, &r);
        T[id].left = l;
        T[id].right = r;
        if(l != NIL) T[l].parent = id;
        if(r != NIL)T[r].parent = id;
    }

    for(int i=0; i<n; i++){
        if(T[i].parent == NIL) root = i;
    }

    // isFirst = true;
    printf("Preorder\n");
    prePerse(root);
    printf("\n");

    // isFirst = true;
    printf("Inorder\n");
    inPerse(root);
    printf("\n");

    // isFirst = true;
    printf("Postorder\n");
    postPerse(root);
    printf("\n");

    return 0;
}