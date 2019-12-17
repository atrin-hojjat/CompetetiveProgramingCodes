#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
int occ[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, q; cin >> n >> m >> q;
  string s, t; cin >> s >> t;
  for(int st = 0; st < n - m + 1; st++) {
    bool ok = false;
    for(int i = 0; i < (int) t.size(); i++) 
      if(s[i + st] != t[i]) ok = true;
    if(!ok) occ[st + 1]++;
  }
  for(int i = 1; i <= n; i++) occ[i] += occ[i - 1];
  while(q--) {
    int l, r; cin >> l >> r;
    r = r - m + 1;
    if(r < l) cout << 0 << endl;
    else cout << occ[r] - occ[l - 1] << endl;
  }
  return 0;
}
