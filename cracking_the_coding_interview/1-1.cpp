#include <iostream>
#include <unordered_map>
#include <bitset>
using namespace std;

// 文字コードがASCIIかUnicodeかを面接官に確認する。
// 今回はASCIIと仮定する。
// ASCIIでは128文字を収録している。
// 8ビットで256文字を扱うことができるが、
// 残り半分はメーカーや国によって異なる文字や記号が収録されている。
// 今回は質問した上で、面接官と128文字を扱うプログラムを作る。

bool is_unique(string s){
  if(s.size() > 128) return false; // 129文字以上の文字列を重複しないで作成することは不可能

  bool isUnique[128];
  for(int i=0; i<s.size(); i++){ // O(n) (ただしn<=128よりO(1)とも言える)
    int charval = s[i];
    if(isUnique[charval]){
      return false;
    }
    isUnique[charval] = true;
  }
  return true;
}

bool is_unique_bitset(string s){
  if(s.size() > 128) return false;

  bitset<128> bitvec(0); // 0は2進数表記で0なので全て0になる
  for(int i=0; i<s.size(); i++){
    int charval = s[i];
    if(bitvec.test(charval)){
      return false;
    }
    bitvec.set(charval);
  }
  return true;
}

int main(void){
  string chara;
  cin >> chara;

  // is_unique()を使う場合
  // if(is_unique(chara)){
  //   cout << "Unique" << endl;
  // }else{
  //   cout << "Not unique" << endl;
  // }

  // is_unique_bitset()を使う場合
  if(is_unique_bitset(chara)){
    cout << "Unique" << endl;
  }else{
    cout << "Not unique" << endl;
  }
  return 0;
}
