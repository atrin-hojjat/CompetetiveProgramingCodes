#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int MaxN = 100 + 10 + 1;

double calc_triangle(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
  double ans = (b.first - a.first) * (b.second - c.second) - (b.second - a.second) * (b.first - c.first);
  if(ans < 0) ans *= -1;
  return ans / 2;
}

double calc_area(vector<pair<double, double>> &v) {
  double ans = 0;
  for(int i = 1; i < v.size() - 1; i++) 
    ans += calc_triangle(v[0], v[i], v[i + 1]);
  return ans;
}

int main() {
  vector<pair<double, double>> vts;
  vector<pair<double, double>> vts2;
  int N;
  double A;
  cin >> A >> N;
  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    vts.push_back({x, y});
  }
  vts2.push_back({(vts[0].first + vts[N - 1].first) / 2, (vts[0].second + vts[N - 1].second) / 2});
  for(int i = 0; i < N - 1; i++) {
    vts2.push_back({(vts[i].first + vts[i + 1].first) / 2, (vts[i].second + vts[i + 1].second) / 2});
  }
  double A1 = calc_area(vts);
  double A2 = calc_area(vts2);
  double out = A1 - A2;
  double L = 2, R = 1000;
  for(int I = 0; I < 100; I++) {
    double mid = L + (R - L) / 2;
    double nout = out * (mid * mid - 4) / (mid * mid);
    if((A2 + nout) <= A * A1) L = mid;
    else R = mid;
  }
  cout << fixed << setprecision(8) << R << endl;
  return 0;
}
