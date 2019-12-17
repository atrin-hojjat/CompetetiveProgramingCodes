#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int Max = 80 + 8;
const int MaxN = 1e5 + 6.66;
const int inf = 1e9 + 7;
int dp[Max][MaxN];
pair<int, int> X[Max];

struct BIT {
  int bit[(int) (5e5 + 6.66)];
  int n = 5e5 + 6.66;

  BIT() {
    for(int i = 0; i < n; i++) bit[i] = inf;
  }

  void add(int x, int y) {
    x = n - x - 10;
    while(x < n) bit[x] = min(bit[x], y), x += x & -x;
  }

  int get(int x) {
    x = n - x - 10;
    int ans = inf;
    while(x) ans = min(bit[x], ans), x ^= x & -x;
    return ans;
  }
} bit;

int main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> X[i].first >> X[i].second;
  sort(X, X + n);
  bit.add(0, 0);
  for(int i = 0; i < n; i++) {
    for(int s = X[i].second; s <= m; s++) 
    {
      int tt = bit.get(max(0, X[i].first - s - 1)) + s - X[i].second;
      bit.add(X[i].first + s, tt);
    }
  }
  cout << bit.get(m) << endl;
  return 0;
}
