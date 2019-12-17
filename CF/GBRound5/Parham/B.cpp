//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MAXn = 1e5 + 100;
int n, ans, b[MAXn], mx, a[MAXn], m[MAXn];

signed main() {
  cin >>n;
  mx = MAXn;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    m[a[i]] = i;
  }
  for(int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  reverse(b, b + n);
  for(int i = 0; i < n; i++) {
    if(mx < m[b[i]]) ans++;
    mx = min(m[b[i]], mx);
  }
  return cout<<ans<<endl, 0;
}
