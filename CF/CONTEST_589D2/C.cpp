#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int _pow(int base, long long exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * base * ans % mod;
  return ans;
}
vector<int> ps;
int main() {
  int x; long long n;
  cin >> x >> n;
  for(int i = 2; i * i <= x; i++) 
    if(x % i == 0) {
      ps.push_back(i);
      while(x % i == 0) x /= i;
    }
  if(x > 1) ps.push_back(x);
  int ans = 1;
  for(auto x : ps) {
    long long zz = 1;
    do {
      zz = 1ll * x * zz ;
      ans = 1ll * ans * _pow(x, n / zz) % mod;
    } while(zz <= n / x);
  }
  cout << ans << endl;
  return 0;
}
