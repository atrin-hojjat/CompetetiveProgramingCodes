#include <bits/stdc++.h>
using namespace std;

struct Bigint {
  for(
}

int main() {
  freopen("13.in", "rt", stdin);
  long long ans = 0;
  long long mod = 10000000000L;
  string strs;
  for(int i = 0; i < 100; i++) {
    cin >> strs;
    long long x = 0;
    for(int i = 10; i >= 1; i--)
      x = 10L * x + (strs[strs.size() - i] - '0');
    ans += x;
    cout << strs << endl;
    cout << "\t\t\t\t\t" << x << endl;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
