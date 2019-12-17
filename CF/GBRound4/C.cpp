#include <iostream>
using namespace std;

const int mod = 998244353;

int main() {
  int w, h; cin >> w >> h;
  int ans = 4;
  for(int i = 2; i < w + h; i++) ans = 1ll * ans * 2 % mod;
  cout << ans << endl;
  return 0;
}
