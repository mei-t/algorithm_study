#include <stdio.h>
using namespace std;

int A[20], n;
int dp[21][2001];

int is_combinated(int i, int m){
  if(dp[i][m] != 2) return dp[i][m];

  if(m == 0) dp[i][m] = 1;
  else if(m < 0  || i >= n) dp[i][m] = 0;
  else if(is_combinated(i+1, m)) dp[i][m] = 1;
  else if(is_combinated(i+1, m-A[i])) dp[i][m] = 1;
  else dp[i][m] = 0;

  return dp[i][m];
}

//bool is_combinated(int i, int m){
//  if(m == 0) return true;
//  else if(m < 0  || i >= n) return false;
//  bool res = is_combinated(i+1, m) || is_combinated(i+1, m-A[i]);
//  return res;
//}

int main(void){
  int q, m;
  for(int i=0; i<21; i++){
    for(int j=0; j<2001; j++){
      dp[i][j] = 2;
    }
  }
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
