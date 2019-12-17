#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef Atrin
	freopen("teleport.in", "rt", stdin);
	freopen("teleport.out", "wt", stdout);
#endif
  int a,b,x,y;cin >> a >> b >> x >> y;
  int ans = min( {abs(a-b),abs(a-x) + abs(b-y),abs(a-y) + abs(b-x) });
  cout << ans << endl;
  return 0;
}
