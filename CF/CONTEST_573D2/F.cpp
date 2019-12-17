#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 2e5 + 666.66;
map<int, vector<int>> m;
map<int, int> cmp;

struct BIT {
  int bit[MaxN];

  void add(int x, int v) {
    while(x < MaxN)
    {
      bit[x] += v; 
      x += x & -x;
    }
  }

  int get(int x) {
    int ans = 0;
    while(x) ans+= bit[x], x ^= x & -x;
    return ans;
  }


  int get_single(int x) { return get(x) - get(x - 1); }
} bit;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n; 
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    m[-y].push_back(x);
    cmp[x];
  }
  int I = 3;
  for(auto&x : cmp) x.second = I++;
  long long ans = 0;
  for(auto X : m) {
    int y = X.first;
    int prv = 0;
    sort(X.second.begin(), X.second.end());
    for(auto x : X.second) {
      x = cmp[x];
      if(bit.get_single(x) == 0) bit.add(x, 1);
    }
    for(auto x : X.second) {
      x = cmp[x];
      int now = bit.get(x);
      ans += 1ll * (now - prv) * (bit.get(MaxN - 1) - now + 1);
      prv = now;
    }
  }
  cout << ans << endl;
  return 0;
}
