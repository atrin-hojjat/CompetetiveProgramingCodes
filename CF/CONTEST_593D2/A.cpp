#ifdef Atrin
  #include <iostream>
  #include <vector>
  #include <map>
  #include <cstring>
#else
  #include <bits/stdc++.h>
#endif
using namespace std;

const int MaxN = 1e5 + 6.66;

int main() {
  int T; cin >> T;
  while(T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i <= b; i++) {
      ans = max(ans, min(2 * a, b - i) / 2 * 3 + min(2 * i, c) / 2 * 3);
    }
    cout << ans << endl;
  }
  return 0;
}
