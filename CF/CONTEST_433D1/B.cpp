#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const int MAXK = 1e6+6.66;
const long long inf = 1e16+6.66;
struct Flight {
  int day;
  int in;
  int out;
  int price;
  bool operator<(const Flight&f) const {
    return day < f.day;
  }
} flights[MAXN];
long long price [MAXN];
long long inc[MAXK];
long long outc[MAXK];

int main() {
  int n,m,k;cin >> n >> m >> k;
  for(int i = 0;i<m;i++) cin >> flights[i].day >> flights[i].in >> flights[i].out >> flights[i].price;
  sort(flights,flights + m);
  fill(price,price + n+1,inf);
  int inf_cnt = n;
  long long ans = 0;
  for(int lday = 1e6,w = m-1;lday > -1;lday -- ) {
    while ( w > -1 && flights[w].day >= lday ) {
      if( flights[w].out == 0 ) { w--;continue; };
      if( price[flights[w].out] == inf ) {
        ans += flights[w].price;
        price[flights[w].out] = flights[w].price;
        inf_cnt--;
      } else if( price[flights[w].out] > flights[w].price) {
        ans += -price[flights[w].out] + flights[w].price;
        price[flights[w].out] = flights[w].price;
      }
      w--;
    }
    if( inf_cnt == 0 ) outc[lday] = ans;
    else outc[lday] = inf;
  }
  ans = 0,inf_cnt = n;
  fill(price,price+n+1,inf);
  for(int lday = 0,w = 0;lday <= 1e6;lday ++ ) {
    while( w < m && flights[w].day <= lday ) {
      if(flights[w].in == 0 ) { w++;continue; };
      if( price[flights[w].in] == inf ) {
        ans += flights[w].price;
        price[flights[w].in] = flights[w].price;
        inf_cnt -- ;
      } else if( price[flights[w].in] > flights[w].price) {
        ans += -price[flights[w].in] + flights[w].price;
        price[flights[w].in] = flights[w].price;
      }
      w++;
    }
    if( inf_cnt == 0 ) inc[lday] = ans;
    else inc[lday] = inf;
  }
  ans = inf;
  for(int i = 0;i<1e6-k-1;i++) {
    ans = min( ans, inc[i] + outc[i+k+1] );
  }
  if ( ans >= inf ) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
