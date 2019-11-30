#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void shuffle(vector<int>& cards, size_t i){
    if(i == cards.size()){
        return;
    }

    size_t j = rand()/((RAND_MAX + 1u) / (i + 1));
    swap(cards[i], cards[j]);
    shuffle(cards, i+1);
}

void shuffle(vector<int>& cards){
    shuffle(cards, 0);
}

int main(void){
    vector<int> cards = {7, 35, 1, 50, 24};
    shuffle(cards);
    for(int num: cards){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}