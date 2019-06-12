#include <stdio.h>
#include <cmath>
using namespace std;

const double pi = std::acos(-1);

struct coodinate{
  double x;
  double y;
};

void koch(int d, coodinate p1, coodinate p2){
  if(d==0) return;

  coodinate s, u, t;
  s.x = (2 * p1.x + p2.x) / 3;
  s.y = (2 * p1.y + p2.y) / 3;
  t.x = (p1.x + 2 * p2.x) / 3;
  t.y = (p1.y + 2 * p2.y) / 3;
  u.x = s.x + (t.x - s.x) * cos(pi / 3) - (t.y - s.y) * sin(pi / 3);
  u.y = s.y + (t.x - s.x) * sin(pi / 3) + (t.y - s.y) * cos(pi / 3);

  koch(d-1, p1, s);
  printf("%f %f\n", s.x, s.y);
  koch(d-1, s, u);
  printf("%f %f\n", u.x, u.y);
  koch(d-1, u, t);
  printf("%f %f\n", t.x, t.y);
  koch(d-1, t, p2);
}

int main(void){
  int n;
  coodinate start, end;
  start.x = 0;
  start.y = 0;
  end.x = 100;
  end.y = 0;

  scanf("%d", &n);
  printf("%f %f\n", start.x, start.y);
  koch(n, start, end);
  printf("%f %f\n", end.x, end.y);
  return 0;
}
