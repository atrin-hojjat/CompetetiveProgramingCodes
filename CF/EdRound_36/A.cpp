#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;cin >> k >> n;
  int ans = 1e9+7;
  for(int i = 0 ;i<k;i++) {
    int x;cin >> x;
    if(n%x==0) ans = min(ans,n/x);
  }
  cout << ans << endl;
}
