#include <iostream>
#include <unordered_map>
using namespace std;

int computeMulti(int smaller, int bigger, unordered_map<int, int> numMap){
    if(smaller == 1){
        return bigger;
    }

    if(numMap.find(smaller) != numMap.end()){
        return numMap[smaller];
    }

    int half = computeMulti(smaller / 2, bigger, numMap);
    if(smaller % 2){
        bigger = half + bigger;
    }else{
        bigger = half;
    }
    numMap.insert({smaller, half + bigger});
    return half + bigger;
}

int multiply(int num1, int num2){
    int smaller = num1 < num2 ? num1 : num2;
    int bigger = num1 < num2 ? num2 : num1;
    return computeMulti(smaller, bigger, unordered_map<int, int>());
}

int main(void){
    cout << "3 * 5 = " << 3*5 << endl;
    cout << multiply(3, 5) << endl;
    cout << "16 * 83 = " << 16*83 << endl;
    cout << multiply(16, 83) << endl;
    return 0;
}