#include <bits/stdc++.h>
using namespace std;

int t1,t2,t3,t4;
int main() {
  string str;cin >> str;
  for(auto w : str ) {
    if( w == '1') {
      t3 += t2;
      t2 += t1 ;
      t1 ++;
    } else {
      t4 += t3;
      t3 += t2;
    }
  }
  cout << t4 << endl;
}
