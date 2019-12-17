#include <iostream>
using namespace std;

const int MaxN = 2e5 + 6.66;
int par[MaxN];

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;

    for(int i = 0; i <= n; i++) par[i] = -1;
    int ans = 3e6;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      if(par[x] == -1) {
        par[x] = i;
        continue;
      }
      ans = min(i - par[x] + 1, ans);
      par[x] = i;
    }
    cout << (ans <= n ? ans : -1) << endl;
  }
  return 0;
}
