#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
int a[2][MAXN];

int main() {
  int T;scanf("%d",&T);
  for(int tt = 1;tt<=T;tt++) {
    memset(a,0,sizeof a);
    int n;scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",a[i%2] + i/2);
    sort( a[0],a[0] + (n+1)/2 );
    sort( a[1],a[1] + n/2 );
    printf("Case #%d: ",tt);
    bool ok = true;
    for(int i = 0;i<n-1;i++) 
      if( a[i%2][i/2] > a[(1+i)%2][(i+1)/2] ) {
        ok = false;
        printf("%d\n",i);
      }
    if( ok ) printf("OK\n");
  }
  return 0;
}
