#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <set>
#include <tuple>
using namespace std;

const int MaxN = 32;
pair<long double, long double> pts[MaxN];
bool _in[MaxN];
vector<pair<long double, long double>> polys[MaxN];

tuple<long double, long double, long double> get_line(pair<long double, long double> p1, pair<long double, long double> p2) {
  long double a = (p2.second - p1.second);
  long double b = (p1.first - p2.first);
  long double c = - a * p2.first - b * p2.second;
  return make_tuple(a, b, c);
}

int main() {
  int W, P; cin >> W >> P;
  for(int i = 0; i < P; i++) cin >> pts[i].first >> pts[i].second;
  for(int i = 0; i < W; i++) {
    int M; cin >> M;
    while(M--) {
      long double x, y; cin >> x >> y;
      polys[i].push_back({x, y});
    }
  }
  long double ans = 0;
  _in[0] = true;
  for(int i = 1; i < P; i++) {
    if(pts[i] == pts[i - 1]) {
      _in[i] = _in[i - 1];
      continue;
    }
    auto [a, b, c] = get_line(pts[i], pts[i - 1]);
    set<pair<long double, long double>, function<bool(pair<long double, long double>, pair<long double, long double>)>> 
      xs([=] (pair<long double, long double> x, pair<long double, long double> y) -> bool {
          return abs(pts[i - 1].first - x.first) + abs(pts[i - 1].second - x.second) < abs(pts[i - 1].first - y.first) + abs(pts[i - 1].second - y.second);
        });
    for(int j = 0; j < W; j++) {
      for(int t = 1; t <= polys[j].size(); t++) {
        int n = polys[j].size();
        auto [A, B, C] = get_line(polys[j][i % n], polys[j][(i - 1)]);
        if(A * b == a * B) continue;
        long double intersectionx = (B * -c + -b * C) / (a * B - A * b);
        long double intersectiony = (-A * -c + a * C) / (a * B - A * b);
        if(min({pts[i].first, pts[i - 1].first, polys[j][i % n].first, polys[j][i - 1].first}) <= intersectionx &&
            max({pts[i].first, pts[i - 1].first, polys[j][i % n].first, polys[j][i - 1].first}) >= intersectionx)
          if(min({pts[i].second, pts[i - 1].second, polys[j][i % n].second, polys[j][i - 1].second}) <= intersectiony &&
              max({pts[i].second, pts[i - 1].second, polys[j][i % n].second, polys[j][i - 1].second}) >= intersectiony)
          {
            xs.insert({intersectionx, intersectiony});
          }
      }
    }
    _in[i] = (xs.size() % 2) ^ _in[i - 1];
    pair<long double, long double> prv = pts[i - 1];
    bool cnt = _in[i - 1];
    for(auto x : xs) {
      if(!cnt) {
        long double dx = prv.first - x.first;
        long double dy = prv.second - x.second;
        ans = max(ans, sqrtl(dx * dx + dy * dy) / 2);
        if(pts[i - 1] == prv) 
          ans = max(ans, sqrtl(dx * dx + dy * dy));
      }
      prv = x;
      cnt ^= 1;
    }
    if(!cnt) {
      long double dx = prv.first - pts[i].first;
      long double dy = prv.second - pts[i].second;
      ans = max(ans, sqrtl(dx * dx + dy * dy));
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
