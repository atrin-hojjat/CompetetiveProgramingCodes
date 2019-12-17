#include <bits/stdc++.h>
using namespace std;

const int MaxM = 5e5 + 6.66;
const int MaxN = 12;
const int Max = 1 << 12;
const int MaxV = 100 + 10 + 1;
int cnt[Max];
int cs[Max];
int ps[MaxV][Max];
int w[MaxN];

int get(string&str) {
  int val = 0;
  for(auto x : str) val = 2 * val + x - '0';
  return val;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, q; cin >> n >> m >> q;
  for(int i = 0; i < n; i++) cin >> w[n - 1 - i];
  for(int i = 0; i < m; i++) {
    string str; cin >> str;
    cnt[get(str)]++;
  }
  int tot = (1 << n) - 1;
  for(int mask = 0; mask < (1 << n); mask++) 
    for(int i = 0; i < n; i++)
      if((mask >> i) & 1) cs[mask] += w[i];
  for(int mask = 0; mask < (1 << n); mask++) {
    for(int m2 = 0; m2 < (1 << n); m2++) {
      int cost = cs[m2];
      if(cost < MaxV) ps[cost][mask] += cnt[mask ^ m2 ^ tot];
    }
    for(int i = 1; i < MaxV; i++) ps[i][mask] += ps[i - 1][mask];
  }
  for(int i = 0; i < q; i++) {
    string str; int k;
    cin >> str >> k;
    cout << ps[k][get(str)] << endl;
  }
  return 0;
}
