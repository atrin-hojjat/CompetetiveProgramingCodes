#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int mod = 998244353;
const int inf = 1e9 + 7;
int lEft[MaxN], rIght[MaxN];
int root[MaxN];
int is_fix[MaxN];
int pos[MaxN];
bool DONE = false;
int ans = 0, inv_100, N;
int X[MaxN], V[MaxN], P[MaxN];
int fix_l[MaxN], fix_r[MaxN], gL[MaxN], gR[MaxN], sz[MaxN], tot[MaxN], SUM = 0, sum_l[MaxN], sum_r[MaxN];

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
  }
};

int get_root(int i) {
  return ~root[i] ? root[i] = get_root(root[i]) : i;
}

int merge(int u, int v) {
  u = get_root(u), v = get_root(v);
//  if(u == v) return ;
  if(sz[u] < sz[v]) swap(u, v);
  root[v] = u;
  sz[u] += sz[v];
  gL[u] = min(gL[u], gL[v]);
  gR[u] = max(gR[u], gR[v]);
  int ADD = 0, AD1 = tot[v], AD2 = tot[u];
  if(v < u) {
    if(fix_r[v] == inf) AD1 = (AD1 - sum_l[v]);
    if(AD1 < 0) AD1 += mod;
    if(fix_l[u] == -1) AD2 = (AD2 - sum_r[u]);
    if(AD2 < 0) AD2 += mod;
  } else {
    if(fix_l[v] == -1) AD1 = (AD1 - sum_r[v]);
    if(AD1 < 0) AD1 += mod;
    if(fix_r[u] == inf) AD2 = (AD2 - sum_l[u]);
    if(AD2 < 0) AD2 += mod;
  }
  cout << u << " " << v << endl;
  ADD = 1ll * AD1 * AD2 % mod;
  (SUM -= tot[u] + tot[v]) %= mod; if(SUM < 0) SUM += mod;
  if(sz[u] == N) SUM = 1;
  ADD = 1ll * ADD * SUM % mod;
  cout << ADD << " " << SUM << endl;
  if(v < u) {
    tot[u] = (1ll * sum_l[v] * tot[u] % mod + 1ll * sum_r[u] * tot[v] % mod - 1ll * sum_l[v] * sum_r[u] % mod) % mod;
    if(fix_r[v] < inf) {
      tot[u] = (tot[u] - 1ll * sum_l[v] * tot[u] % mod + 1ll * sum_l[v] * sum_r[u] % mod);
    }
    if(fix_l[u] > -1) {
      tot[u] = (tot[u] - 1ll * sum_r[u] * tot[v] % mod + 1ll * sum_l[v] * sum_r[u] % mod);
    }
    if(fix_r[v] < u && fix_l[u] > v) DONE = true;
  } else {
    tot[u] = (1ll * sum_r[v] * tot[u] % mod + 1ll * sum_l[u] * tot[v] % mod - 1ll * sum_r[v] * sum_l[u] % mod) % mod;
    if(fix_l[v] > -1) {
      tot[u] = (tot[u] - 1ll * sum_r[v] * tot[u] % mod + 1ll * sum_r[v] * sum_l[u] % mod);
    }
    if(fix_r[u] < inf) {
      tot[u] = (tot[u] - 1ll * sum_l[u] * tot[v] % mod + 1ll * sum_r[v] * sum_l[u] % mod);
    }
    if(fix_l[v] > u && fix_r[u] < v) DONE = true;
  }
  sum_l[u] = (1ll * sum_l[u] * sum_l[v]) % mod;
  sum_r[u] = (1ll * sum_r[u] * sum_r[v]) % mod;
  fix_r[u] = min(fix_r[u], fix_r[v]);
  fix_l[u] = max(fix_l[u], fix_l[v]);
  (SUM += tot[u]) %= mod;
  return ADD;
}

struct Segment {
  int L[MaxN * 4], R[MaxN * 4], tot[MaxN * 4];

  Segment() {
    build(1, 0, MaxN);
  }

  void build(int id, int l, int r) {
    if(l >= r) return ;
    if(l + 1 == r) {
      tot[id] = 1, L[id] = lEft[l], R[id] = rIght[l];
      return ;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid, r);
    tot[id] = (1ll * L[id << 1] * tot[id << 1 | 1] % mod + 1ll * R[id << 1 | 1] * tot[id << 1] % mod) % mod;
    L[id] = 1ll * L[id << 1] * L[id << 1 | 1] % mod;
    R[id] = 1ll * R[id << 1] * R[id << 1 | 1] % mod;
  }

  tuple<int, int, int> get(int id, int l, int r, int b, int e) {
    if(l >= r) return {0, 1, 1};
    if(l >= e || r <= b) return {0, 1, 1};
    if(l >= b && r <= e) return {tot[id], L[id], R[id]};
    int mid = l + (r - l) / 2;
    tuple<int, int, int> lft = get(id << 1, l, mid, b, e), rght = get(id << 1 | 1, mid, r, b, e);
    return {(1ll * std::get<0>(lft) * std::get<2>(rght) % mod + 1ll * std::get<0>(rght) * std::get<1>(lft) % mod) % mod, 
      (1ll * std::get<1>(lft) * std::get<1>(rght)) % mod, (1ll * std::get<2>(lft) * std::get<2>(rght)) % mod};
  }

  tuple<int, int, int> get(int l, int r) { return get(1, 0, MaxN, l, r); }
} seg;

int calc(int l1, int l2, int r1, int r2) {
  int m = get<0>(seg.get(l2, r1));
  if(l2 == r1) m = 1;
  int ll = get<1>(seg.get(l1, l2));
  int rr = get<2>(seg.get(r1, r2));
  cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
  cout << m << " " << ll << " " << rr << endl;
  return 1ll * m * ll % mod * rr % mod;

}

int force(int I, int stat) {
  int r = get_root(I);
  int ret = 0;
  if(stat == 1) {
    if(I < fix_r[r]) {
      ret = calc(gL[r], max(fix_l[r], I) + 1, min(fix_r[r], gR[r]), gR[r]);
    }
  } else {
    if(I - 1 > fix_l[r]) {
      ret = calc(gL[r], max(gL[r], fix_l[r]) + 1, min(I - 1, fix_r[r]), gR[r]);
    }
  }
  if(stat == 2) DONE = fix_r[r] < I, fix_l[r] = min(fix_l[r], I - 1);
  else if(stat == 1) DONE = fix_l[r] >= I, fix_r[r] = max(fix_r[r], I);
  SUM += 1ll * (tot[r] = calc(gL[r], max(gL[r], fix_l[r]) + 1, min(gR[r], fix_r[r]), gR[r])) - tot[r];
  if(SUM < 0) SUM += ans;
  return ret;
}

void init(int n) {
  for(int i = 0; i < n; i++) fix_l[i] = -1, fix_r[i] = +1e9 + 7, sz[i] = 1, root[i] = -1, 
    sum_l[i] = lEft[i], sum_r[i] = rIght[i], tot[i] = 1, gR[i] = 1 + (gL[i] = i), (SUM += tot[i]) %= mod;
  seg = Segment();
}

int main() {
  int n; cin >> n;
  inv_100 = inv(100);
  for(int i = 0; i < n; i++) {
    cin >> X[i] >> V[i] >> P[i];
    lEft[i] = 1ll * (100 - P[i]) * inv_100 % mod;
    rIght[i] = 1ll * P[i] * inv_100 % mod;
  }
  N = n;
  init(n);
  set<pair<DIS, pair<int, int>>> S;
  for(int i = 1; i < n; i++) {
    DIS a, b, c;
    a.dis = X[i] - X[i - 1];
    a.v = V[i] + V[i - 1];
    b.dis = X[i] - X[i - 1];
    b.v = V[i] - V[i - 1];
    c.dis = X[i] - X[i - 1];
    c.v = V[i - 1] - V[i];
    /**/S.insert({a, {i, 0}});
    if(b.v > 0) S.insert({b, {i, 1}});
    if(c.v > 0) S.insert({c, {i, 2}});
  }
  for(auto u : S) {
    DIS x = u.first;
    int I = u.second.first;
    int stat = u.second.second;
    cout << x.dis << " " << x.v << " " << I << " " << stat << endl;
    if(stat == 0) {
      ans += 1ll * merge(I, I - 1) * x.dis % mod * inv(x.v) % mod;
    } else if(stat == 1) {
      ans += 1ll * force(I, 1) * x.dis % mod * inv(x.v) % mod;
    } else ans += 1ll * force(I, 2) * x.dis % mod * inv(x.v) % mod;
    if(ans > mod) ans -= mod;
    cout << ans << endl;
    if(DONE) break;
  }
  cout << ans << endl;
	return 0;
}
