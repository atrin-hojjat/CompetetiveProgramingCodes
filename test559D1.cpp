#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, k; scanf("%d %d", &n, &k);
  for(long long i = 0; i < (1LL << n); i++) {
    map<int, int> m;
    bool ok = true;
    for(int j = 1; j < k; j++) {
      for(int w = 0; w + j - 1 < n; w++) {
        int res = (i >> w) & ((1 << j) - 1);
        m[res]++;
      }
      for(auto x : m) if(x.second == 1) { ok = false; break; }
      if(!ok) break;
      m.clear();
    }
    if(!ok) continue;
    for(int w = 0; w + k - 1 < n; w++) {
      int res = (i >> w) & ((1 << k) - 1);
      m[res]++;
    }
    ok = false;
    for(auto x : m) if(x.second == 1) { ok = true; break; }
    if(ok) {
      for(int j = n - 1; j > -1; j--)
        cout << ((i >> j) & 1);
      cout << endl;
    }
  }
  return 0;
}
