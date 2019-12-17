#include <bits/stdc++.h>
using namespace std;

int main ( ) {
  int n,k;cin >> n >> k;
  cout << "YES" << endl;
  if ( k % 2 == 0 ) {
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
    cout << ".";
    for ( int i = 0;i<k/2;i++ ) cout << "#" ; 
    for ( int i = 0;i<n-k/2-1;i++ ) cout << "." ; cout << endl;
    cout << ".";
    for ( int i = 0;i<k/2;i++ ) cout << "#" ; 
    for ( int i = 0;i<n-k/2-1;i++ ) cout << "." ; cout << endl;
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
  } else if ( k > 3 ) {
    
    for ( int i = 0;i<n;i++ ) cout << "." ; cout << endl;
    cout << ".##" ;
    for ( int i = 0;i<(k-3)/2;i++ ) cout << "#" ;
    for ( int i = 0;i<n - (k + 1 ) /2 -1 ;i++) cout << "." ; cout << endl;
    cout << ".#." ;
    for ( int i = 0;i<(k-3)/2;i++ ) cout << "#" ;
    for ( int i = 0;i<n - (k + 1 ) /2 -1 ;i++) cout << "." ; cout << endl;
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
  } else if ( k > 1 ) {
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
    for ( int i = 0;i<n/2-1;i++ ) cout << "." ;
    cout << "###" ;
    for ( int i = 0;i<n/2-1;i++ ) cout << "." ;
    cout << endl ;
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
  } else if  (k == 1 ) {
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
    for ( int i = 0;i<n/2;i++ ) cout << "." ;
    cout << "#";
    for ( int i = 0;i<n/2;i++ ) cout << "." ;
    cout << endl; 
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
    for ( int i = 0;i<n;i++ ) cout << "." ;cout << endl;
  }
  return 0;
}
