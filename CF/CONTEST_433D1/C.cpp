#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
int seg[MAXN * 2];
int pos[MAXN];
vector<int> vv[MAXN],vr[MAXN];
long long ans[MAXN];

void add(int x,int val) {
  for( seg[x += MAXN] += val; x > 1;x >>= 1) seg[x >> 1] = seg[x] + seg[x^1];
}

int get(int l,int r) {
  int ans = 0;
  for(l += MAXN,r += MAXN;l<r;l>>=1,r>>=1) {
    if( l & 1 ) ans += seg[l++];
    if( r & 1 ) ans += seg[--r];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,q;cin >> n >> q;
  for(int i = 1;i<=n;i++) cin >> pos[i];
  vector<int> ss;
  for(int i = 1;i<=n;i++) ss.push_back( i ) ;
  sort(ss.begin(),ss.end() );
  for(int Q = 0;Q<q;Q++) {
    int l,d,r,u;cin >> l >>d >> r >> u;
    ans[Q] = 1LL * d * ( n - u -1) ;
    vv[l].push_back( { Q,{d,u} } );
    vr[r].push_back( { Q,{d,u} } );
  }
  for(int i = 1;i<=n;i++) {
    
  }
  return 0;
}
