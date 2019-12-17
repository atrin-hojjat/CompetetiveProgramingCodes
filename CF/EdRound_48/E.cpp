#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
pair<int, int> segs[MaxN];
long long sum[MaxN * 2];
pair<long double, int> aa[MaxN * 2];

long double zero(pair<int, int> x1, pair<int, int> x2) {
  long double c1 = (x1.first - x2.first) * 1.l / (x1.second - x2.second);
  long double c2 = -c1 * x2.second + x2.first;
  return c2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int s, a, b; cin >> s >> a >> b;
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    segs[i].first = x;
    segs[i].second = y;
    aa[i << 1] = {x, 1};
    aa[i << 1 | 1] = {y, -1};
  }
  for(int i = 1; i < 2 * n; i++)
    if(aa[i].second == 1 && i > 0) sum[i] = sum[i - 1] + abs(aa[i].first - aa[i - 1].first);
    else sum[i] = sum[i - 1];
  sum[2 * n] = sum[2 * n - 1];
  int Q; cin >> Q;
  long double tot = b - a;
  cout << fixed << setprecision(11);
  while(Q--) {
    int x, y; cin >> x >> y;
    long double s1 = zero({a, s}, {x, y});
    long double s2 = zero({b, s}, {x, y});
    pair<long double, int> S1 = {s1, 0}, S2 = {s2, 0};
    int a1 = lower_bound(aa, aa + 2 * n, S1) - aa;
    int a2 = lower_bound(aa, aa + 2 * n, S2) - aa;
    long double ans = 0;
    if(a1 == a2) ans = (a1 == 2 * n || aa[a1].second == 1 ? abs(s1 - s2) : 0);
    else {
      ans = sum[a2 - 1];
      ans -= sum[a1];
      if(a2 == 2 * n || aa[a2].second == 1) ans += abs(s2 - (long double) aa[a2 - 1].first);
      if(aa[a1].second == 1) ans += abs(s1 - (long double) aa[a1].first);
    }
    ans = ans * (y - s) / y;
    ans = tot - ans;
    cout << ans << endl;
  }
  return 0;
}
