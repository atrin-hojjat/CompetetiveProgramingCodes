#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
int el[MAXN],st[MAXN];

int main() {
  int n,m,c1,c2,v; scanf("%d %d %d %d %d",&n,&m,&c2,&c1,&v);
  for( int i = 0;i<c2;i++) scanf( "%d", st + i );
  for(int i = 0;i<c1;i++) scanf( "%d",el + i );
  int q;scanf("%d",&q) ;
  sort( el,el + c1 );
  sort( st,st + c2 );
  while( q -- ) {
    int x1,x2,y1,y2;
    scanf( "%d %d %d %d", &y1,&x1,&y2,&x2 );
    long long ans = 3e15 +  6.66;
    if( y1 == y2 ) {
      ans = abs( x1 - x2 );
      printf( "%lld\n", ans ) ;
      continue;
    }
    int P = upper_bound(st,st+c2,x1)-st;
    for( int p1 = P-1;p1<P+2;p1++)
      if ( p1 > -1 && p1 < c2 ) 
        ans = min( ans,(long long)abs ( st[p1] - x1 ) + abs(st[p1] - x2 ) + abs( y2-y1));
    P = upper_bound(el,el+c1,x1)-el;
    for( int p1 = P-1;p1<P+2;p1++)
      if ( p1 > -1 && p1 < c1 ) 
        ans = min( ans,(long long)abs ( el[p1] - x1 ) + abs(el[p1] - x2 ) + (v -1+ abs( y2-y1) ) / v);
    printf("%lld\n",ans) ;
  }
  return 0;
}
