#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int delta = 10313;
int arr[MaxN];

int& add(int&x, int y) {
  x += y;
  if(x >= delta) x -= delta;
  return x;
}

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) arr[i] = i + 1;
  for(int d = 1; d <= n; d++) {
    if(n % d) continue;
    for(int st = 0; st < n; st += d)
      reverse(arr + st, arr + st + d);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++)
    add(ans, 1ll * arr[i - 1] * i % delta);
  cout << ans << endl;
  return 0;
}
