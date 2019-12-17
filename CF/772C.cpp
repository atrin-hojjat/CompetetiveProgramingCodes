#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
bool forb[MaxN];
vector<int> nums[MaxN];
vector<int> sccs, eds[MaxN];
vector<int> topo;
pair<int, int> dp[MaxN];
bool mark[MaxN];
int phi[MaxN];
bool added[MaxN];

void prep() {
  for(int i = 0; i < MaxN; i++) phi[i] = i;
  for(int i = 2; i < MaxN; i++) {
    if(phi[i] != i) continue;
    for(int j = i; j < MaxN; j += i)
      phi[j] = phi[j] / i * (i - 1);
  }
}

int gcd(int y, int x) {
  return y ? gcd(x % y, y) : x;
}

void dfs(int x) {
  mark[x] = true;
  for(auto y : eds[x]) if(!mark[y]) dfs(y);
  topo.push_back(x);
}

int Pow(int base, int exp, int mod) {
  if(base > mod) base %= mod;
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * base * ans % mod;
  return ans;
}

int main() {
  prep();
  int n,m; scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    forb[x] = true;
  }
  for(int i = 0; i < m; i++) {
    if(forb[i]) continue;
    int cc = gcd(i, m);
    nums[cc].push_back(i);
    if(!added[cc]) sccs.push_back(cc), added[cc] = true;
    else forb[i] = true;
  }
  for(auto x : sccs) {
    for(int y = x + x; y <= m; y += x)
      if(added[y]) eds[x].push_back(y);
  }
  for(auto i : sccs)
    if(!mark[i]) dfs(i);
  for(auto w : topo) {
    pair<int, int> mx = {0, -1};
    for(auto z : eds[w])
      mx = max(mx, {dp[z].first, z});
    dp[w] = {mx.first + (int) nums[w].size(), mx.second};
  }
  pair<int, int> mx = {0, -1};
  for(auto w : sccs)
    mx = max(mx, {dp[w].first, w});
  vector<int> scc_ans;
  pair<int, int> w = mx;
  while(~w.second) {
    scc_ans.push_back(w.second);
    w = dp[w.second];
  }
  int prv = 1;
  vector<int> ans;
  for(auto zz : scc_ans) {
    int a = gcd(zz, m);
    for(auto b : nums[a]) {
      int zz = gcd(prv, m);
      int mm = m / zz;
      int yy = (b / zz) % mm;
      int aa = 1ll * (1ll * yy * Pow(prv / zz, phi[mm] - 1, mm) % mm) % m;
      ans.push_back(aa);
      prv = 1ll * prv * aa % m;
    }
  }
  printf("%d\n", (int) ans.size());
  for(auto x : ans) printf("%d ", x);
  printf("\n");
  return 0;
}
