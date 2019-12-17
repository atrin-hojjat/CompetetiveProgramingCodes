#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
int par[MAXN];
int fward[MAXN];
int bward[MAXN];
int arr[MAXN];

struct BIT {
  int bit[100'006];

  BIT() { memset( bit,0,sizeof bit ) ; };

  void alter(int x,int y) {
    x++;
    while(x< MAXN)
      bit[x] = max(bit[x],y),x += x&-x;
  }

  int get(int x) {
    x++;
    int ans = 0;
    while(x) ans = max(ans,bit[x]),x ^= x&-x;
    return ans;
  }
} f,b;

int main() {
  int n,m;cin >> n >> m;
  for(int i = 0;i<n;i++) {
    int x,y;cin >> x >> y;
    x--,y--;
    par[x] ++;
    par[y+1]--;
  }
  int ans = 0;
  for(int i = 0;i<m;i++)
    arr[i] = ( ans += par[i] );
  for(int i = 0;i<m;i++) {
    fward[i] = 1 + f.get(arr[i]);
    f.alter(arr[i],fward[i]);
  } 
  for(int i = m-1;i>-1;i--) {
    bward[i] = 1 + b.get(arr[i]);
    b.alter(arr[i],bward[i] );
  }
  ans = 0;
  for(int i = 0;i<m;i++) ans = max(ans,fward[i] + bward[i] -1) ;
  cout << ans << endl;
  return 0;
}
