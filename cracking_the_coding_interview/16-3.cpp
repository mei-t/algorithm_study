#include <iostream>
#include <algorithm>
using namespace std;

struct Intersection{
    bool isIntersect;
    double x;
    double y;
};

Intersection noIntersection(){
    Intersection inter;
    inter.isIntersect = false;
    return inter;
}

Intersection computeIntersect(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3){
    double a, b, c, d; // y = a*x + b, y = c*x + d
    double x, y; // 交点
    bool isVertical0 = false;
    bool isVertical1 = false;
    if(x0 == x1){
        isVertical0 = true;
    }else{
        a = (y0 - y1) / (x0 - x1);
        b = y0 - a * x0;
    }
    if(x2 == x3){
        isVertical1 = true;
    }else{
        a = (y2 - y3) / (x2 - x3);
        b = y2 - a * x2;
    }

    if(!isVertical0 && !isVertical1){
        if(a != c){
            x = (d - b) / (a - c);
            y = a * x + b;
        }else{
            return noIntersection(); // b == d なら重なる。b != d なら並行。どちらも「交わる」の定義を満たさない。
        }
    }else if(isVertical0 && !isVertical1){
        y = c * x0 + d;
    }else if(!isVertical0 && isVertical1){
        y = a * x2 + b;
    }else{
        return noIntersection(); //「交わる」の定義を満たさない。
    }

    if(max(min(x0, x1), min(x2, x3)) <= x && x <= min(max(x0, x1), max(x2, x3)) && max(min(y0, y1), min(y2, y3)) <= x && x <= min(max(y0, y1), max(y2, y3))){
        Intersection inter;
        inter.isIntersect = true;
        inter.x = x;
        inter.y = y;
        return inter;
    }else{
        return noIntersection();
    }
}

int main(void){
    return 0;
}