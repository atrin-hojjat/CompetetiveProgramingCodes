#include <bits/stdc++.h>
using namespace std;

int main ( ) {
  string str;cin >> str;
  int n = str.size  ( ), cnt = 0,cnt2 = 0;
  for ( int i = 0;i<n;i++ ) {
    if ( str[i] == '-' ) cnt ++ ;
    else cnt2 ++ ;
  }
  if ( cnt2 && cnt % cnt2 ) cout << "NO" << endl;
  else cout <<"YES" << endl;
  return 0;
}
