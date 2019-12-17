#include <bits/stdc++.h>
using namespace std;

typedef long double ld ;

int main() {
  long double k,d,t;cin >> k >> d >> t;
  long long X = 1LL * (d+k-1)/d;
  long long ll = X * d;
  ld done = 1.0l * k + .5l * (ll-k);
  long long cc = 1LL * t/done;
  ld w = t - cc*done;
  ld ans = cc * ll;
  if(w > k) ans += 1.0l*k + (w-1.0*k)*2;
  else ans +=  1.0l*w;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
