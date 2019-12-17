#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
long long H[MAXN],W [MAXN],C[MAXN];

long long gcd ( long long a,long long b ) {
  return ( a ? gcd ( b % a, a ) : b );
}

int main() {
  int n;scanf("%d",&n);
  set<long long > hs,ws;
  for(int i = 0;i<n;i++) {
    scanf( "%lld %lld %lld",W + i,H + i, C + i);
    ws.insert( W[i] );
    hs.insert( H[i] );
  }
  if( n != ws * hs ) {
    cout << 0 << endl;
    return 0;
  }
  long long xx = *ws.begin();
  long long cc = 0;
  for(int i = 0;i<n;i++) if( W[i] == xx ) cc = gcd ( cc , C[i] );
  
}
