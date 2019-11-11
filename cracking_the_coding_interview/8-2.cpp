#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;

class RobotRoute{
public:
    RobotRoute(int r, int c, unordered_set<pair<int, int>> noEntry){
        this -> r = r;
        this -> c = c;
        this -> noEntry = noEntry;
    }

    vector<pair<int, int> > findRoute(){
        findRoute(0,0);
        return route;
    }

    void findRoute(int i, int j){
        if(i == r-1 && j == c-1){
            return;
        }

        if(i < r-1 && noEntry.find(make_pair(i + 1, j)) == noEntry.end()){
            route.push_back(make_pair(i, j));
            findRoute(i+1, j);
        }else if(j < c-1 && noEntry.find(make_pair(i, j + 1)) == noEntry.end()){
            route.push_back(make_pair(i, j));
            findRoute(i, j+1);
        }else{
            noEntry.insert(make_pair(i, j));
            route.clear();
            findRoute(0, 0);
        }
    }

private:
    unordered_set<pair<int, int>> noEntry;
    vector<pair<int, int> > route;
    int r;
    int c;
};

int main(void){
    return 0;
}