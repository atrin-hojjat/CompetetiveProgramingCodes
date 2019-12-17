#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6e5 + 6.66;
int arr[MAXN];
int ansp[MAXN];
int t[MAXN];

int main() {
  int n,k;cin >> n >> k;
  priority_queue<pair<int,int>> q;
  for(int i = 1;i<=n;i++) cin >> arr[i];
  for(int i = 1;i<=k;i++) q.push( { arr[i] , -i });
  long long ans = 0;
  for(int i = k+1;i<=n+k;i++) {
    if( !q.size() ) {
      ansp[i] = i;
      continue;
    }
    if( i > n ) {
      ans += 1LL * (i + q.top().second) * q.top().first;
      ansp[i] = -q.top().second;
      q.pop();
      continue;
    }
    if( q.top().first > arr[i] ) {
      ans += 1LL * ( i + q.top().second ) * q.top().first ;
      ansp[i] = -q.top().second;
      q.pop();
      q.push( {arr[i],-i} );
    } else ansp[i] = i;
  }
  cout << ans << endl;
  for(int i = k+1;i<=n+k;i++) t[ansp[i]] = i;
  for(int i = 1;i<=n;i++) cout << t[i] << " ";cout << endl;
  return 0;
}
