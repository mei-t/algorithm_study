#include <stdio.h>
#define MAX 45

int F[MAX];

int fibonacci(int n){
  if(F[n] != -1) return F[n];
  if(n == 0 || n == 1){
    F[n] = 1;
  }else{
    F[n] = fibonacci(n-1) + fibonacci(n-2);
 }
  return F[n];
}

int main(void){
  int n, f;
  scanf("%d", &n);
  for(int i=0; i<=n; i++){
    F[i] = -1;
  }
  f = fibonacci(n);
  printf("%d\n", f);
  return 0;
}
