#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 2e5 + 6.66;
int a[MaxN], b[MaxN], c[MaxN];
int d[MaxN], e[MaxN];
int dp[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int k1, k2, k3; cin >> k1 >> k2 >> k3;
  for(int i = 0; i < k1; i++) cin >> a[i];
  for(int i = 0; i < k2; i++) cin >> b[i];
  for(int i = 0; i < k3; i++) cin >> c[i];
  sort(a, a + k1);
  for(int i = 0; i < k3; i++) c[i] *= -1;
  sort(c, c + k3);
  for(int i = 0; i < k1; i++) d[i] = -a[i];
  reverse(d, d + k1);
  for(int i = 0; i < k3; i++) e[i] = -c[i];
  reverse(e, e + k3);
  int n = k1 + k2 + k3;
  for(int i = 0; i <= n; i++) {
    int t = n - i + 1;
    int w = upper_bound(c, c + k3, -t) - c;
    int ans = i - w + (k3 - w) - (upper_bound(d, d + k1, -t) - d);
    if(i > 0) dp[i] = min(ans, dp[i - 1]);
    else dp[i] = ans;
  }
  int Ans = dp[n] + k1;
  for(int i = 0; i <= n; i++) {
    int t = i;
    int w = upper_bound(a, a + k1, t) - a;
    int ans = dp[n - i] + k1 + i - 2 * w - (upper_bound(e, e + k3, t) - e);
    Ans = min(ans, Ans);
  }
  cout << Ans << endl;
  return 0;
}
