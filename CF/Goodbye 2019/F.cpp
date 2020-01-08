#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int Sq = 400;
int arr[MaxN];
int par[MaxN];
int sv[MaxN];
int cnt[MaxN * Sq];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  int n = s.size();
  for(int i = 0; i < n; i++) arr[i] = s[i] - '0';
  par[0] = arr[0];
  vector<int> ones;
  for(int i = 1; i < MaxN; i++) par[i] = par[i - 1] + arr[i];
  for(int i = 0; i < MaxN; i++)
    if(arr[i]) ones.push_back(i);
  long long ans = 0;
  for(int i = 0, pt = 0; i < n; i++) {
    if(pt >= ones.size()) break;
    if(ones[pt] < i) pt++;
    for(int j = pt; j < min((int) ones.size(), pt + n / Sq); j++) {
      int cnt = j - pt + 1;
      int dif;
      if(j + 1 < ones.size()) {
        dif = ones[j + 1] - ones[j];
      } else {
        dif = n - ones[j];
      }
      long long su = max(1ll * ones[j] - i, 1ll * (Sq + 1) * cnt - 1);
      int tot = (ones[j] - i + dif) / cnt - su / cnt;
      if(tot > 0) ans += tot;
    }
  }
  for(int k = 1; k <= min(n, Sq); k++) {
    cnt[n * k]++;
    for(int i = 0; i < n; i++)
      cnt[n * k + i + 1 - par[i] * k]++;
    for(int i = 0; i < n; i++)
    {
      int t = n * k + i + 1 - par[i] * k;
      ans += 1ll * cnt[t] * (cnt[t] - 1) / 2;
      cnt[t] = 0;
    }
    cnt[n * k] = 0;

  }
  cout << ans << endl;
  return 0;
}
