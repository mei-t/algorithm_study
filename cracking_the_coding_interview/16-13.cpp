#include <iostream>
using namespace std;

class Line{
public:
    Line(double a_, double b_, bool isParallelXAxis_, double xVal_ = 0);

private:
    double a;
    double b;
    bool isParallelXAxis;
    double xVal;
};

Line::Line(double a_, double b_, bool isParallelXAxis_, double xVal_){
    a = a_;
    b = b_;
    isParallelXAxis = isParallelXAxis_;
    xVal = xVal_;
}


Line findLine(double x1, double y1, double len1, double x2, double y2, double len2){
    double xc1 = x1 + len1 / 2;
    double yc1 = y1 + len1 / 2;
    double xc2 = x2 + len2 / 2;
    double yc2 = y2 + len1 / 2;
    if(xc1 == xc2){
        return Line(0, 0, true, xc1);
    }
    double a = (yc1 - yc2) / (xc1 - xc2);
    double b = xc1 * a - yc1;
    return Line(a, b, false);
}

int main(void){
    return 0;
}