#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin >> n;
  int pos,l,r;cin >> pos >> l >> r;
  int ans = 0;
  if(l==1) {
    if(r<n) ans += abs(pos-r) +1;
  }
  else if(r==n) {
    ans += abs(l-pos)+1;
  }
  else ans = min(abs(l-pos)+1 + abs(r-l) + 1,abs(r-pos) + 1 + abs(r-l) + 1);
  cout << ans << endl;
  return 0;
}
