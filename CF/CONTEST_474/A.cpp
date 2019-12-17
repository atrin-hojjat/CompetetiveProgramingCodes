#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;cin >> str;
  for(int i = 0;i<str.size()-1;i++) if ( str[i] > str[i+1] ) { cout << "NO" << endl; return 0 ; };
  int a = 0,b = 0,c = 0;
  for(auto w : str) 
    if( w == 'a')
      a++;
    else if( w == 'b')
      b++;
    else c++;
  if( a > 0 && b > 0 && ( c == a || c == b ) ) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
