#include <bits/stdc++.h>
using namespace std;

const int MaxN = 60;
const int mod = 1e6 + 3;

int main() {
  vector<pair<int, int>> v; 
  for(long long x = 2, i = 1; i <= 51; i++, x <<= 1) {
    long long c = x + 1;
    bool ok = true;
    for(int k = 2; k <= sqrt(c); k++) 
      if(c % k == 0) {
        ok = false;
        break;
      }
    if(ok) v.push_back({i, c % mod});
  }
  cout << v.size() << endl;
  int sum = 0;
  for(int i = 0; i < (1 << (int) v.size()); i++) {
    int t = 0;
    int mul = 1;
    for(int j = 0; j < (int) v.size(); j++)
      if((i >> j) & 1) t += v[j].first, mul = 1ll * mul * v[j].second % mod;
    for(int x = t; t < 50 && x < 51; x++) 
      mul = (mul + mul) % mod;
    sum += mul;
    if(sum >= mod) sum -= mod;
  }
  cout << sum << endl;
  return 0;
}
