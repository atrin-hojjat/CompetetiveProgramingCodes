#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MaxN = 2e5 + 6.66;
const long long inf = 13e17 + 11;
int cs[MaxN];
int L[MaxN], R[MaxN];
vector<pair<int, long long>> dp[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, k, q; cin >> n >> m >> k >> q;
  for(int i = 0; i < n + 1; i++) L[i] = MaxN, R[i] = -1;
  for(int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    L[x] = min(L[x], y);
    R[x] = max(R[x], y);
  }
  for(int i = 0; i < q; i++) cin >> cs[i];
  for(int i = 0; i < q; i++) cs[i]--;
  sort(cs, cs + q);
  for(int i = 0; i < n; i++) {
    if(R[i] == -1) {
      if(i == 0) {
        dp[i].push_back({cs[0], inf});
        dp[i].push_back({cs[1], inf});
      }
      continue;
    }
    set<int> s;
    int ls = lower_bound(cs, cs + q, L[i]) - cs;
    if(ls < q) 
      s.insert(cs[ls]);
    if(ls > 0) 
      s.insert(cs[ls - 1]);
    ls = lower_bound(cs, cs + q, R[i]) - cs;
    if(ls < q)
      s.insert(cs[ls]);
    if(ls > 0) 
      s.insert(cs[ls - 1]);
    for(auto x : s) dp[i].push_back({x, inf});
  }
  {
    if(~R[0])
    {
      int base = R[0];
      for(auto&x : dp[0])
        x.second = base + abs(x.first - R[0]);
    } else for(auto&x : dp[0]) x.second = x.first;
  }
  int T = n - 1;
  for(T = n - 1; T > -1 && R[T] == -1; T--);
  for(int i = 1; i < T; i++) {
    if(R[i] == -1) {
      for(auto x : dp[i - 1]) dp[i].push_back(x);
      continue;
    }
    int base = R[i] - L[i];
    for(auto y : dp[i - 1])
      for(auto&x : dp[i]) {
        x.second = min(x.second, 0ll + base + y.second +
            min(abs(y.first - L[i]) + abs(x.first - R[i]),
              abs(y.first - R[i]) + abs(x.first - L[i])));
      }
  }
  long long ans = inf;
  if(T > 0) {
    int base = R[T] - L[T];
    for(auto x : dp[T - 1])
      ans = min(ans, 0ll + base + min(abs(x.first - L[T]), abs(x.first - R[T])) + x.second);
  } else ans = R[0];
  cout << ans + T << endl;
  return 0;
}
