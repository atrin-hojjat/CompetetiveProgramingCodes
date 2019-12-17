#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int mod = 1e9 + 7;
vector<int> tree[MaxN];
int inv_2;
int PLUS[MaxN];
int one[MaxN];
int two[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

bool dfs(int v, int par = -1) {
  int sum = 1, f = -1;
  bool X = true;
  for(auto u : tree[v])
    if(u != par) {
      X &= dfs(u, v);
      f = u;
      sum = 1ll * sum * (two[u] + one[u]) % mod;
    }
  int children = tree[v].size() - (par != -1);
  if(children == 1) {
    one[v] = one[f];
    if(X) one[v] = (one[v] + two[f]) % mod;
    two[v] = 0;
    if(par == -1) two[v] = one[v];
  } else if(children == 0) {
    one[v] = 1; two[v] = 0;
  } else {
    int a = 0, b = 0, cnt = 0;;
    int mul = 1;
    for(auto u : tree[v]) {
      if(u == par) continue;
      if((two[u] + one[u]) % mod == 0) { mul = 1ll * mul * one[u] % mod; cnt++; continue; }
      int c = 1ll * _pow(two[u] + one[u], mod - 2) * one[u] % mod;
      a += c;
      if(a >= mod) a -= mod;
      b += 1ll * c * c % mod;
      if(b >= mod) b -= mod;
    }
    if(cnt > 2) {
      return children > 1;
    } else if(cnt == 1) {
      two[v] = 1ll * sum * a % mod * mul % mod;
      one[v] = 1ll * sum;
    } else if(cnt == 2) {
      two[v] = 1ll * sum % mod * mul % mod;
      one[v] = 0ll;
    } else {
      two[v] = 1ll * sum * (1ll * a * a % mod - b + mod) % mod * inv_2 % mod;
      one[v] = 1ll * a * sum % mod;
    }
    cout << one[v] << " " << a << " " << sum << endl;
    int s = 1, C = 0, M = 1, MU = 1;
    for(auto x : tree[v]) 
      if(x != par) 
      {
        if(two[x]) 
          s = 1ll * s * two[x] % mod, MU = 1ll * MU * _pow(two[x], mod - 2) % mod * one[x] % mod; 
        else C++, M = 1ll * M * one[x];
      }
    if(C == 0) one[v] = (one[v] + s) % mod;
    if(par == -1) {
      if(C == 0) two[v] = (two[v] + s + 1ll * MU * s % mod) % mod;
      else if(C < 2) (two[v] = 1ll * two[v] + 1ll * M * s % mod) %= mod;
    }
  }
  cout << v << " " << sum << " " << two[v] << " " << one[v] << endl;
  return children > 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  inv_2 = _pow(2, mod - 2);
  for(int i = 1; i < n; i++) {
    int v, u;
    cin >> v >> u;
    tree[v].push_back(u);
    tree[u].push_back(v);
  }
  dfs(1);
  cout << two[1] << endl;
  return 0;
}
