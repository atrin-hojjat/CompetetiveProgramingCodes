#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 8000 + 800 + 80 + 8;
int cnt[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k; cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    cnt[x - 1]++;
  }
  if(k == 1) {
    cout << cnt[0] << endl;
    return 0;
  } 
  sort(cnt, cnt + k);
  long long ans = 3e15 + 6;
  for(int i = 0; i <= k; i++) {
    int mx = 0;
    for(int j = k - i; j < k; j++) mx = max(cnt[j], mx);
    for(int j = 0; j < k - i; j++)
      if(j < k - i - j - 1) mx = max(mx, cnt[j] + cnt[k - i - j - 1]);
      else if(j == k - i - j - 1) mx = max(mx, cnt[j]);
    ans = min(ans, 1ll * (i + ((k - i + 1) / 2)) * mx);
  }
  cout << ans << endl;
  return 0;
}
