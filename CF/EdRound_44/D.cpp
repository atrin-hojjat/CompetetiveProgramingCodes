#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long n,H; cin >> n >> H;
  long long l = 0, r = 2e9 + 9;
  auto func = [H](long long x) -> long long {
    if(x > H) {
      return (x - H) * H + (x - H) * (x - H - 1) / 2 + x * (x + 1) / 2;
    } else 
      return x * (x + 1) / 2;
  };
  while(l < r) {
    long long mid = l + (r - l + 1) / 2;
    if(func(mid) > n) r = mid - 1;
    else l = mid;
  }
  long long cc = func(l);
  long long cnt = l <= H ? l : 2 * l - H;
  cout << cnt + (n - cc + l - 1) / l << endl;
  return 0;
}
