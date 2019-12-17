#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
pair<int, int> points[MaxN];
long long ans;
map<long double, int> cmp;
int bit[MaxN * 4];
int n, l, wm;

void add(int v, int x = 1) {
  while(v < 4 * MaxN)
    bit[v] += x, v += v & -v;
}

int get(int v) {
  int ans = 0;
  while(v)
    ans += bit[v], v ^= v & -v;
  return ans;
}

void compress() {
  for(int i = 0; i < n; i++) {
    cmp[points[i].first] = cmp[points[i].first * -1] 
      = cmp[points[i].first + l] = cmp[-points[i].first - l] = 0;
  }
  int I = 0;
  for(auto & x : cmp)
    x.second = ++I;
}

void solve() {
  memset(bit, 0, sizeof bit);
  if(wm == 1) return;
  for(int i = 0; i < n; i++) {
    if(!points[i].second) break;
    if(points[i].first < 0) break;
    if(points[i].second < 0) {
      add(cmp[points[i].first + l], 1);
    } else {
      long double xx = 1.l * (wm + 1) * (points[i].first) / (wm - 1);
      auto it = cmp.upper_bound(xx);
      if(it == cmp.end()) continue;
      else if(it->second > 1)
      {
        ans += get(MaxN * 4 - 1) - get(it->second - 1);
      } else ans += get(MaxN * 4 - 1);
    }
  }
}

int main() {
  cin >> n >> l >> wm;
  for(int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
  compress();
  long long aa = 0, bb = 0;
  for(int i = 0; i < n; i++)
    if((points[i].first >= 0) != (points[i].second > 0)) {
      if(points[i].first < 0 && points[i].first + l > 0) continue;
      if(points[i].first >= 0) aa++;
      else bb++;
    }
  ans += aa * bb;
  for(int i = 0; i < n; i++) {
    if(points[i].first < 0 && points[i].first + l > 0)
    {
      if(points[i].second > 0) {
        ans += aa;
      } else {
        ans += bb;
      }
      points[i].second = 0;
    }
  }
  sort(points, points + n);
  reverse(points, points + n);
  solve();
  reverse(points, points + n);
  for(int i = 0; i < n; i++) points[i].first = -points[i].first - l;
  for(int i = 0; i < n; i++) points[i].second *= -1;
  solve();
  cout << ans << endl;
  return 0;
}
