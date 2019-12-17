#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6.66;
int arr[MAXN];
int szz[MAXN];

int main() {
  int n ; cin >> n;
  string str;cin >> str;
  int K = (str.size() + 1) /2;
  int sz,pans = 0;
  if( str.size() % 2 ) {
    sz = 1,pans = 1;
  } else {
    sz = 2;
    if(str[K-1] == str[K]) pans = 2;
    else pans = -1;
  }
  szz[K] = sz;
  arr[K] = pans;
  for(int k = K-1;k>0;k--) {
    szz[k] = (sz += 2);
    if( str[k-1] == str[n - k] ) {
      arr[k] = pans + ( ( pans + 1) % 2);
      pans ++;
    } else pans = arr[k] = -1;
  }
  for(int i = 1;i<=K;i++) cout << (arr[i]==szz[i] ? arr[i] - 2 : arr[i] ) << " ";
  cout << endl;
  return 0;
}
