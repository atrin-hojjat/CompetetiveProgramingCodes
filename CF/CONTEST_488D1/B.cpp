#include <bits/stdc++.h>
using namespace std;

const int MaxN = 20;
pair<int, int> ps1[MaxN];
pair<int, int> ps2[MaxN];
vector<int> ps1_x[MaxN];
vector<int> ps2_x[MaxN];

int main() {
  int ans = -1;
  int mxx = 0;
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> ps1[i].first >> ps1[i].second;
    ps1_x[ps1[i].first].push_back(ps1[i].second);
    ps1_x[ps1[i].second].push_back(ps1[i].first);
  }
  for(int i = 0; i < m; i++) {
    cin >> ps2[i].first >> ps2[i].second;
    ps2_x[ps2[i].first].push_back(ps2[i].second);
    ps2_x[ps2[i].second].push_back(ps2[i].first);
  }
  for(int i = 0; i < n; i++) {
    int cc = 0;
    for(int ww = 0; ww < 2; ww++) {
      for(auto x : ps2_x[ps1[i].first]) {
        if(x != ps1[i].second) {
          cc++;
          if(~ans && ans != ps1[i].first) ans = 0;
          else ans = ps1[i].first;
          break;
        }
      }
      swap(ps1[i].first, ps1[i].second);
    }
    mxx = max(mxx, cc);
  }
  if(ans == 0) {
    for(int i = 0; i < m; i++) {
      int cc = 0;
      for(int ww = 0; ww < 2; ww++) 
      {
        for(auto x : ps1_x[ps2[i].first])
          if(x != ps2[i].second)
          {
            cc++;
            if(~ans && ans != ps2[i].first) ans = 0;
            else ans = ps1[i].first;
            break;
          }
        swap(ps2[i].first, ps2[i].second);
      }
      mxx = max(mxx, cc);
    }
  }
  if(ans > 0)cout << ans << endl;
  else if(ans == -1) cout << ans << endl;
  else if(mxx <= 1) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}
