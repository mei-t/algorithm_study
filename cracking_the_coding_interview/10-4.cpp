#include <iostream>
#include <vector>
using namespace std;

class MyArray{
public:
    MyArray(vector<unsigned int> input){
        v = input;
    }
    int elementAt(int i){
        if(i < v.size()){
            return v[i];
        }else{
            return -1;
        }
    }
private:
    vector<unsigned int> v;
};

int findIndex(MyArray& myArray, int x, int left, int right){
    if(left >= right){
        return -1;
    }
    int mid = (left + right) / 2;
    if(myArray.elementAt(mid) == x){
        return mid;
    }else if(myArray.elementAt(mid) == -1 || myArray.elementAt(mid) > x){
        return findIndex(myArray, x, left, mid);
    }
    return findIndex(myArray, x, mid+1, right);
}

// constにしたらelementAt呼べなくなったのはなぜ
int findIndex(MyArray& myArray, int x){
    int i = 1;
    while(myArray.elementAt(i) != -1){
        i *= 2;
    }
    return findIndex(myArray, x, 0, i);
}

int main(void){
    vector<unsigned int> v = {0, 1, 2, 8, 10, 100, 726};
    MyArray myArray = MyArray(v);
    cout << findIndex(myArray, 10) << endl; // 4
    cout << findIndex(myArray, 3) << endl; // -1
    return 0;
}