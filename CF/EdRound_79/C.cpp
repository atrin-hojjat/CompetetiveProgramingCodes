#include <iostream>
using namespace std;

const int MaxN = 1e5 + 6.66;
int a[MaxN];
int b[MaxN];

int main() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
      b[a[i]] = i;
    }
    int mx = 0;
    long long ans = 0;
    for(int j = 0; j < m; j++) {
      int x; cin >> x;
      if(mx < b[x]) ans += 2 * (b[x] - j) + 1;
      else ans++;
      mx = max(mx, b[x]);
    }
    cout << ans << endl;
  }
  return 0;
}
