#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000+6.66;
int ans[MAXN];
int l[MAXN],r[MAXN];
set<pair<int,int>> vv[MAXN*5];

int main() {
  int T;cin >> T;
  while(T--) {
    memset(ans,0,sizeof ans);
    int n;cin >> n;
    for(int i = 0;i<n;i++) {
      cin >> l[i] >> r[i];
    }
    int sec = 0;
    for(int i = 0;i<n;i++) {
      if(sec < r[i]) {
        ans[i] = max(++sec,l[i]);
        sec = max(sec,l[i]);
      }
    }
    for(int i = 0;i<n;i++) cout << ans[i] << " ";cout << endl;
  }
  return 0;
}
