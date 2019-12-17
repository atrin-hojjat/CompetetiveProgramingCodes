#include <iostream>
#include <vector>
using namespace std;

#define int long long

const int MaxN = 3e5 + 6.66;
long long c[MaxN], cc[MaxN], dp[MaxN], c2[MaxN];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    int n;
    long long k; cin >> n >> k;
    for(int i = 0; i < n; i++) {
      cin >> c[i];
    }
    long long L = 0, R = 6e17 + 6.66;
    while(L < R) {
      long long mid = L + (1 + R - L) / 2;
      long long cnt = 0;
      for(int i = 0; i < n; i++) c2[i] = c[i];
      for(int i = 0; i < n; i++) cc[i] = c2[i];
      for(int i = 0; i < n; i++) cnt += cc[i] / mid;
      for(int i = 0; i < n; i++) cc[i] %= mid;
      for(int i = 1; i < n; i++) {
        if(cc[i] + cc[i - 1] < mid && c2[i] >= mid) cnt--, cc[i] += mid, c2[i] -= mid;
        if(cc[i] + cc[i - 1] < mid) continue;
        cnt++;
        cc[i] += cc[i - 1] - mid;
      }
      if(cnt >= k) L = mid;
      else R = mid - 1;
    }
    cout << k * L << endl;
  }
  return 0;
}
