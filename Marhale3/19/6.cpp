#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6;
const int MAX = 100 ;
const int mod = 22273;
int score [ MAXN ];
int scoremx [ MAXN ];
int knap [ MAX * 2 ] ;
int Ans = 0;

void backtrack ( int i ) {
  if ( i == 6 ) {
    int sum = 0;
    for ( int i = 0;i<6;i++ )
      sum += score [i] ;
    if ( sum != 100 ) return ;
    memset ( knap,0,sizeof knap ) ;
    knap [ 0 ] = 1;
    for ( int i = 0;i<6;i++ )
      for ( int j = 100;j>-1;j-- ) 
        knap [ score [i] + j ] |= knap [ j ] ;
    int ans = 0;
    for ( int i = 0;i<=100;i++ ) ans += knap[i];
    if ( Ans < ans ) {
      for ( int i = 0;i<6;i++ ) scoremx [ i ] = score [ i ];
      Ans = ans;
    }
    return ;
  }
  for ( int j = 10;j<26;j++ ) 
  {
    score [ i ] = j;
    backtrack ( i + 1 ) ;
  }
}

int KnapIt ( ) {
  memset ( knap,0,sizeof knap ) ;
  knap [ 0 ] = 1;
  for ( int i = 0;i<6;i++ )
    for ( int j = 100;j>-1;j-- ) 
      knap [ score [i] + j ] |= knap [ j ] ;
  int ans = 0;
  for ( int i = 0;i<=100;i++ ) ans += knap[i];
  return ans;
}

int main ( ) 
{
  backtrack ( 0 ) ;
  cout << Ans << " " << 1LL * ( 1LL * Ans * Ans % mod ) * Ans % mod << endl;
  for ( int i = 0;i<6;i++ ) cout << scoremx [i] << " " ;cout << endl;
  for ( int i = 0;i<6;i++ ) cin >> score [i] ;
  cout << KnapIt ( ) << endl;
  return 0;
}
