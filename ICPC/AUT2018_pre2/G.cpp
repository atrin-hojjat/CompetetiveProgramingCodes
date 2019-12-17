#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

long double x, y;

long double get(long double a, long double b) {
  return sqrt(pow((a - x), 2) + pow(b - y, 2));
}

long double D(long double a, long double b, long double c, long double res1, long double res2) {
  if(b > c) swap(b, c);
  if(a >= b && a <= c) return res1;
  return res2;
}

int main() {
  long double x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;

  long double ans = min(
      min(D(x, x1, x2, abs(y - y1), min(get(x1, y1), get(x2, y1))), 
        D(x, x1, x2, abs(y - y2), min(get(x1, y2), get(x2, y2)))),
      min(D(y, y1, y2, abs(x - x1), min(get(x1, y1), get(x1, y2))),
        D(y, y1, y2, abs(x - x2), min(get(x2, y1), get(x2, y2)))));
  printf("%.3Lf\n", ans);
//  cout << setprecision(3) << fixed << ans << endl;
  return 0;
}

