#ifdef Atrin
  #include <iostream>
  #include <map>
  #include <set>
#else
  #include <bits/stdc++.h>
#endif

using namespace std;

const int MaxN = 1e5 + 6.66;

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int s, c; cin >> c >> s;
    c = min(s, c);
    int x = s / c;
    long long ans = 1ll * x * x * (c - s % c) + 1ll * s % c *(x + 1) * (x + 1);
    cout << ans << endl;
  }
  return 0;
}
