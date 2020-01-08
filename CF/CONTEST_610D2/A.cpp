#ifdef Atrin
  #include <iostream>
#else
  #include <bits/stdc++.h>
#endif
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    int s1 = c - r;
    int s2 = c + r;
    int a1 = min(a, b);
    int a2 = max(a, b);
    int l = max(a1, s1);
    int R = min(a2, s2);
    if(R < l) R = l;
    cout << a2 - a1 - (R - l) << endl;
  }
  return 0;
}
