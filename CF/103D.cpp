#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+6.66;
const int SQ = 557.666;
long long arr[MAXN];
long long par[SQ][SQ];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0;i<n;i++) cin >> arr[i];
  for(int i = n/SQ;i>-1;--i) 
    for(int j = 1;j<SQ;j++) {
      par[i][j] = arr[i*SQ];
      int a = i * SQ + j;
      while( a<n &&a%SQ) par[i][j] += arr[a],a+=j;
      if(a<n) par[i][j] += par[a/SQ][j];
    }
  int Q; cin >> Q;
  while(Q--) {
    int a,b;cin >> a >> b;
    a--;
    long long ans = 0;
    if(b >= SQ)
      while(a<n) ans += arr[a],a += b;
    else { 
      while( a < n && a % SQ ) ans += arr[a],a += b;
      if(a< n) ans += par[a/SQ][b];
    }
    cout << ans << "\n";
  }
  return 0;
}
