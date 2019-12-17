#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
long long arr[MAXN];
long long par[MAXN];

int main() {
  int n,d,b;cin >> n >> d >> b;
  for(int i = 1;i<=n;i++) cin >> arr[i];
  for(int i = 1;i<=n;i++) par[i] = par[i-1] + arr[i];
  long long far = d;
  long long backl = 0;
  long long backr = 0;
  int ans = 0;
  for(int i = 1;2* i<=n+1;i++) {
    int l = i;
    int r = n + 1 - l;
    if( l == r ) break;
    if( l + far >= r ) break;
    long long s = par[l + far] - par[l] + par[r-1] - par[ r - far -1];
    if( l + far > r - far -1 ) s -= par[l + far] - par[r - far -1];
    if( s >= backl + backr + 2 * b - arr[l] - arr[r] ) {
      backl -= b - arr[l];
      backr -= b - arr[r];
    } else {
      ans ++;
      if( s <= backl + backr ) { backl += arr[l], backr += arr[r],ans ++ ; continue ; }
      if( s
    }
    far += d;
  }
  cout << ans << endl;
  return 0;
}
