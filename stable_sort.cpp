#include <iostream>
#include <string>
using namespace std;

struct Card {
  char suit; 
  int value;
  int index;
};

void output(struct Card c[], int n){
  for(int i=0; i<n; i++){
    cout << c[i].suit << c[i].value << (i!=n-1 ? " " : "");
  }
  cout << endl;
}

void IsStable(struct Card c[], int n){
  for(int i = 0; i<n; i++){
    if((c[i].value == c[i+1].value) && (c[i].index > c[i+1].index)){
      cout << "Not stable" << endl;
      return;
    }
  }
  cout << "Stable" << endl;
  return;
}

void BubbleSort(struct Card c[], int n){
  for(int i=0; i<n; i++){
    for(int j=n-1; j>i; j--){
      if(c[j].value < c[j-1].value){
        swap(c[j],c[j-1]);
      }
    }
  }
  output(c, n);
  IsStable(c, n);
}

void SelectionSort(struct Card c[], int n){
  for(int i=0; i<n; i++){
    int minj = i;
    for(int j=i; j<n; j++){
      if(c[j].value < c[minj].value){ minj = j;}
    }
    swap(c[i], c[minj]);
  }
  output(c, n);
  IsStable(c, n);
}

int main(void){
  int n;
  cin >> n;
  Card c1[n], c2[n];
  for (int i=0; i<n; i++){
    cin >> c1[i].suit >> c1[i].value;
    c1[i].index = i;
  }

  for(int i=0; i<n; i++){
    c2[i] = c1[i];
  }

  BubbleSort(c1, n);
  SelectionSort(c2, n);
  return 0;
}
