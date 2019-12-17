#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10 + 1;
int arr[MAXN];

int main() {
#ifndef Atrin
	freopen("taming.in", "rt", stdin);
	freopen("taming.out", "wt", stdout);
#endif
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> arr[i];
  if(~arr[0] && arr[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  arr[0] = 0;
  int a = -1,mn = 0,mx = 0;
  for(int i = n-1;i>-1;i--) {
    if(~arr[i]) {
      if(~a && arr[i]!= a) 
      {
        cout << -1 << endl;
        return 0;
      }
      if(arr[i] == 0) mn ++;
      a = arr[i] -1;
    } else {
      if(!~a) mx ++;
      if(a==0) mn ++;
      a = max(-1,a-1);
    }
  }
  cout << mn << " " << mx+mn << endl;
  return 0;
}
