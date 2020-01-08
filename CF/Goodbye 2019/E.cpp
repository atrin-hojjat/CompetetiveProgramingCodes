#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MaxN = 1e3 + 6.66;
int X[MaxN], Y[MaxN];

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];
  while(true) {
    vector<int> ans;
    vector<int> tt[4];
    for(int i = 0; i < n; i++) {
      int x = X[i], y = Y[i];
      if((x & 1) == (y & 1)) ans.push_back(i + 1);
      tt[(x & 1) + ((y & 1) << 1)].push_back(i + 1);
    }
    if(ans.size() && ans.size() < n) {
      cout << ans.size() << endl;
      for(auto x : ans) cout << x << " "; cout << endl;
      return 0;
    }
    for(int i = 0; i < 4; i++)
      if(tt[i].size() && tt[i].size() < n) {
        cout << tt[i].size() << endl;
        for(auto x : tt[i]) cout << x << " "; cout << endl;
        return 0;
      }
    for(int i = 0; i < n; i++) X[i] >>= 1, Y[i] >>= 1;
  }
  return 0;
}
