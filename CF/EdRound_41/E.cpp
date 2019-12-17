#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
int arr[MAXN];
map<int,int> cmp;

struct Bit {
  int bit[400'012];

  Bit() {
    memset( bit,0,sizeof bit);
  }

  void add(int x,int val) {
    while( x < 2*MAXN ) 
      bit[x] += val, x += ( x & -x );
  }

  int get(int x) {
    if(!x) return 0;
    int ans = 0;
    while( x )  ans += bit[x], x ^= (x&-x);
    return ans ;
  }
} bb;

void compress(int n) {
  for(int i = 0;i<n;i++) cmp[arr[i]] = 0;
  for(int i = 0;i<n;i++) cmp[i+1] = 0;
  int I = 0;
  for(auto&w : cmp) w.second = ++I; 
}

int main() {
  int n;scanf("%d",&n);
  bb = Bit();
  for(int i = 0;i<n;i++) scanf("%d",arr + i);
  vector<int> nsort;
  for(int i = 0;i<n;i++) nsort.push_back(i);
  sort(nsort.begin(),nsort.end(),[](int x,int y) { return ( arr[x] == arr[y] ? x < y : arr[x] < arr[y] ); } );
  compress(n);
  int T = 0;
  long long ans = 0;
  for( auto i : nsort) {
    while( T < n && arr[i] > T )
      bb.add(cmp[arr[T]],1),T++;
    ans += bb.get( MAXN * 2 -1) - bb.get(cmp[i+1]-1);
    ans -= ( i < arr[i] );
  }
  cout << ans/2 << endl;
  return 0;
}
