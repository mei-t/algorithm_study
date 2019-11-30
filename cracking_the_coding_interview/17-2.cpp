#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void shuffle1(vector<int>& cards, size_t i){
    if(i == cards.size()){
        return;
    }

    size_t j = rand()/((RAND_MAX + 1u) / (i + 1));
    swap(cards[i], cards[j]);
    shuffle1(cards, i+1);
}

void shuffle2(vector<int>& cards, size_t i){
    if(i == cards.size()){
        return;
    }

    srand(time(0));
    size_t j = rand()/((RAND_MAX + 1u) / (i + 1));
    swap(cards[i], cards[j]);
    shuffle2(cards, i+1);
}

void print(const vector<int>& cards){
    for(int num: cards){
        cout << num << " ";
    }
    cout << endl;
}

void shuffle(vector<int>& cards){
    shuffle1(cards, 0);
    print(cards);
    shuffle2(cards, 0);
    print(cards);
}

int main(void){
    vector<int> cards = {7, 35, 1, 50, 24};
    shuffle(cards);
    return 0;
}