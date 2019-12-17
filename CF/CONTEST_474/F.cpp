#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
map<int,int> cmp[MAXN];
pair<pair<int,int>,int> E[MAXN];
vector<pair<int,int>> eds[MAXN];
struct Bit {
  vector<int> bit;
  int N;

  Bit() { N = 0; bit = vector<int>() ; }

  Bit(int n) : N(n+10) {
    bit = vector<int> (N,0);
  }

  void add(int x,int val) {
    x = N - x ;
    while( x < N ) 
      bit[x] = max(bit[x],val),x += x & -x;
  }

  int get(int x) {
    x = N - x ;
    int ans = 0;
    while( x ) 
      ans = max(ans,bit[x]), x ^= x & -x;
    return ans;
  }
};

void compress(int n) {
  for(int i = 1;i<=n;i++) {
    for( auto w : eds[i] ) cmp[i][w.second] = 0;
    int I = 0;
    for( auto&k : cmp[i] ) k.second = ++I;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m;cin >> n >> m;
  Bit *bt = new Bit[n+1];
  for(int i = 0;i<m;i++) {
    int a,b,c;cin >> a >> b >> c;
    E[i] = {{a,b},c};
    eds[a].push_back( { b,c } );
    eds[b].push_back( { a,c } );
  }
  compress(n);
  for(int i = 1;i<=n;i++) bt[i] = Bit(cmp[i].size());
  for(int i = m-1;i>-1;i--) {
    int a = E[i].first.first,b = E[i].first.second,c = E[i].second;
    bt[a].add(cmp[a][c],1+bt[b].get(cmp[b].upper_bound(c)->second) );
  }
  int ans = 0;
  for(int i = 1;i<=n;i++) ans = max(ans,bt[i].get(1));
  cout << ans << endl;
  return 0;
}
