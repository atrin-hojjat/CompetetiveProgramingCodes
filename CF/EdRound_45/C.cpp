#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 6.66;
int f[MaxN];
int l[MaxN];
int cnt[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    int open = 0;
    int ff = 0;
    for(auto x : str) {
      if(x == ')') {
        if(open == 0) ff++;
        else open--;
      } else open++;
    }
    f[i] = ff;
    l[i] = open;
  }
  for(int i = 0; i < n; i++) {
    if(f[i] && l[i]) continue;
    if(f[i]) continue;
    cnt[l[i]]++;
  }
  int ww = 0;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if(f[i] && l[i]) continue;
    if(f[i] == 0 && l[i] == 0) {
      ww++;
      continue;
    }
    if(l[i]) continue;
    ans += cnt[f[i]];
  }
  ans += 1ll * ww * ww;
  cout << ans << endl;
  return 0;
}
