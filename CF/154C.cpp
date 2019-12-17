#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int base = 727;
pair<int, int> pw[MaxN];
vector<int> vvs[MaxN];
map<pair<int, int>, int> cnt;

pair<int, int> operator*(pair<int, int> x, int y) {
  return {1ll * x.first * y % mod, 1ll * x.second * y % mod2};
}

void add(int&x, int m, int y) {
  x += y;
  if(x > m) x -= m;
}

void add(pair<int, int>&x, pair<int, int> y) {
  add(x.first, mod, y.first);
  add(x.second, mod2, y.second);
}

int main() {
  int n, m; scanf("%d %d", &n, &m);
  pw[0] = {1, 1};
  for(int i = 1; i < MaxN; i++) pw[i] = pw[i - 1] * base;
  for(int i = 0; i < m; i++) {
    int x, y; scanf("%d %d", &x, &y);
    vvs[--x].push_back(--y);
    vvs[  y].push_back(  x);
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    pair<int, int> hash = {0, 0};
    for(auto x : vvs[i]) {
      add(hash, pw[x]);
    }
    cnt[hash]++;
    add(hash, pw[i]);
    cnt[hash]++;
  }
  for(auto x : cnt) ans += 1ll * x.second * (x.second - 1);
  cout << (ans >> 1) << endl;
  return 0;
}
