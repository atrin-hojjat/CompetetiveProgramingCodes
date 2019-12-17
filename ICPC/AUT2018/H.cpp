#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <vector>
#include <math.h>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
long double xs[MaxN];
long double vs[MaxN];

int main() {
  long double V, A, X; cin >> V >> A >> X;
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> xs[i] >> vs[i];
  vector<pair<long double, long double>> ts;
  for(int i = 0; i < N; i++) {
    long double dv, delta1, delta2;
    if(A == 0) {
      if(V > vs[i])
        ts.push_back({(xs[i] - 50) / (V - vs[i]), (xs[i] - 50) / (V - vs[i])});
      continue;
    }
    dv =  V - vs[i];
    delta1 = sqrtl(dv * dv + 2 * A * (xs[i] - 50));
    delta2 = sqrtl(dv * dv + 2 * A * (xs[i] + 50));
    ts.push_back({(-dv + delta1) / A, (-dv + delta2) / A});
  }
  long double max_time = 0;
  if(A == 0) {
    max_time = X / V;
  } else {
    max_time = (-V + sqrtl(V * V + 2 * A * X)) / A;
  }
  auto GET = [V, A, X] (long double t) -> long double {
    return A * t * t / 2.l + V * t;
  };
  sort(ts.begin(), ts.end());
  auto x = ts.begin();
  long double ans = 0;
  while(x != ts.end()) {
    auto t = x + 1;
    while(t != ts.end()) {
      if(t->first >= x->second)
        break;
      t->first = x->second;
      t++;
    }
    ans += max(0.l, GET(min(max_time, max(0.l, x->second))) - GET(min(max_time, max(0.l, x->first))));
    x++;
  }
  cout << fixed << setprecision(10) << X - ans << endl;
  return 0;
}
