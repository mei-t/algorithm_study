#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <functional>
#include <limits>
using namespace std;

int main(void){
  string a[200];
  int s[200];
  int top = 0;
  for(int i=0; i<numeric_limits<int>::max(); i++){
    if(cin.eof()){break;}
    cin >> a[i];
    if(a[i].empty()){
// ignore empty string
    }else if(all_of(a[i].begin(), a[i].end(), [](unsigned char c){return isdigit(c);})){
      top++;
      s[top] = stoi(a[i]);
    }else if(a[i] == "+"){
      s[top-1] = s[top-1] + s[top];
      top-=1;
    }else if(a[i] == "-"){
      s[top-1] = s[top-1] - s[top];
      top-=1;
    }else if(a[i] == "*"){
      s[top-1] = s[top-1] * s[top];
      top-=1;
    }
  }
  cout << s[1] << endl;
  return 0;
}
