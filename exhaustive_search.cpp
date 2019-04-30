#include <stdio.h>

int A[2000], n;

bool is_combinated(int i, int m){
  if(m == 0) return true;
  else if(m < 0  || i >= n) return false;
  bool res = is_combinated(i+1, m) || is_combinated(i+1, m-A[i]);
  return res;
}

int main(void){
  int q, m;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &q);

  for(int i=0; i<q; i++){
    scanf("%d", &m);
    if(is_combinated(0, m)){
      printf("yes\n");
    }else{
      printf("no\n");
    }
  }
  return 0;
}
