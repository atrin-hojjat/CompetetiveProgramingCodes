#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int mod = 998244353;
int left[MaxN], right[MaxN];
int root[MaxN];
int is_fix[MaxN];
int pos[MaxN];
bool DONE = false;
int ans = 0, inv_100;
int X[MaxN], V[MaxN], P[MaxN];
int fix_l[MaxN], fix_r[MaxN], sz[MaxN], tot[MaxN], SUM = 0, sum_l[MaxN], sum_r[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * base * ans % mod;
  return ans;
}

int inv(int x) { return _pow(x, mod - 2); }

struct DIS {
  int v, dis;

  bool operator<(const DIS& d) const {
    return 1ll * d.v * dis < 1ll * v * d.dis;
  :}
};

int get_root(int i) {
  return root[i] ? root[i] = get_root(root[i]) : i;
}

int merge(int u, int v) {
  u = get_root(u), v = get_root(v);
  if(u == v) return ;
  if(sz[u] < sz[v]) swap(u, v);
  root[v] = u;
  sz[u] += sz[v]
  int ADD = 0;
  ADD = (tot[v] + tot[u]); if(ADD > mod) ADD -= mod;
  if(v < u) {
    if(fix_l[v] > v) ADD = (ADD - sum_l[v]);
    if(ADD < mod) ADD += mod;
    if(fix_r[u] < u) ADD = (ADD - sum_r[u]);
    if(ADD < mod) ADD += mod;
  } else {
    if(fix_r[v] < v) ADD = (ADD - sum_r[v]);
    if(ADD < mod) ADD += mod;
    if(fix_l[u] > u) ADD = (ADD - sum_l[u]);
    if(ADD < mod) ADD += mod;
  }
  sum_l[u] = (sum_l[u] + sum_l[v]);
  if(sum_l[u] > mod) sum_l[u] -= mod;
  sum_r[u] = (sum_r[u] + sum_r[v]);
  if(sum_r[u] > mod) sum_r[u] -= mod;
  SUM -= tot[u];
  ADD = 1ll * ADD * sum;
  if(v < u) {
    tot[u] = (1ll * sum_l[v] * tot[u] % mod + 1ll * sum_r[u] * tot[v] % mod - 1ll * sum_l[v] * sum_r[u] % mod) % mod;
    if(fix_r[v] < u) {
      tot[u] = (tot[u] - 1ll * sum_l[v] * tot[u] % mod + 1ll * sum_l[v] * sum_r[u] % mod);
    }
    if(fix_l[u] > v) {
      tot[u] = (tot[u] - 1ll * sum_r[u] * tot[v] % mod + 1ll * sum_l[v] * sum_r[u] % mod);
    }
    if(fix_l[v] < u && fix_r[u] > v) DONE = true;
  } else {
    tot[u] = (1ll * sum_r[v] * tot[u] % mod + 1ll * sum_l[u] * tot[v] % mod - 1ll * sum_r[v] * sum_l[u] % mod) % mod;
    if(fix_l[v] > u) {
      tot[u] = (tot[u] - 1ll * sum_r[v] * tot[u] % mod + 1ll * sum_r[v] * sum_l[u] % mod);
    }
    if(fix_r[u] < v) {
      tot[u] = (tot[u] - 1ll * sum_l[u] * tot[v] % mod + 1ll * sum_r[v] * sum_l[u] % mod);
    }
    if(fix_r[v] > u && fix_l[u] < v) DONE = true;
  }
  fix_r[u] = min(fix_r[u], fix_r[v]);
  fix_l[u] = max(fix_l[u], fix_l[v]);
  SUM += tot[u];
  return ADD;
}

int force(int I, int stat) {
  int r = get_root(I);
  
}

void init() {
  for(int i = 0; i < MaxN; i++) fix_l[i] = -1, fix_r[i] = +1e9 + 7, tot[i] = 0, sz[i] = 1, root[i] = -1, sum_l[i] = left[i], sum_r[i] = right[i], tot[i] = 1;
}

int main() {
  int n; cin >> n;
  inv_100 = inv(100);
  for(int i = 0; i < n; i++) {
    cin >> X[i] >> V[i] >> P[i];
    left[i] = 1ll * (100 - P[i]) * inv_100 % mod;
    right[i] = 1ll * P[i] * inv_100 % mod;
  }
  init();
  set<pair<DIS, pair<int, int>>> s;
  for(int i = 1; i < n; i++) {
    DIS a, b, c;
    a.dis = X[i] - X[i - 1];
    a.v = V[i] + V[i - 1];
    b.dis = X[i] - X[i - 1];
    b.v = V[i] - V[i - 1];
    c.dis = X[i] - X[i - 1];
    c.v = V[i - 1] - V[i];
    S.insert({a, {i, 0}});
    if(b.v > 0) S.insert({b, {i, 1}});
    if(c.v > 0) S.insert({c, {i, 2}});
  }
  for(auto u : S) {
    DIS x = u.first;
    int I = u.second.first;
    int stat = u.second.second;
    if(stat == 0) {
      ans += 1ll * merge(I, I - 1) * x.dis % mod * inv(x.v);
    } else if(stat == 1) {
      ans += 1ll * force(I, 1) * x.dis % mod * inv(x.v) % mod;
    } else ans += 1ll * force(I, 2) * x.dis % mod * inv(x.v) % mod;
    if(ans > mod) ans -= mod;
    if(DONE) break;
  }
  cout << ans << endl;
  return 0;
}
