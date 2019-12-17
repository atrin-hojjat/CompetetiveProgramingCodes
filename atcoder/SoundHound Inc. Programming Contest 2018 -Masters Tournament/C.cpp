#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, n, m; cin >> n >> m >> d;
  long double pos = 0;
  if(d == 0) pos = n;
  else if(2 * d < n) pos = 2 * (n - 2 * d) + 2 * d;
  else pos = n;
  pos /= (1ll * n * n);
  pos *= m - 1;
  cout << fixed << setprecision(10) << pos << endl;
  return 0;
}
