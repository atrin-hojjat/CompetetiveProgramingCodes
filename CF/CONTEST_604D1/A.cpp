#ifdef Atrin
  #include <iostream>
  #include <vector>
  #include <map>
  #include <set>
  #include <math.h>
#else
  #include <bits/stdc++.h>
#endif
using namespace std;

const int MaxN = 4e5 + 6.66;
int arr[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(n == 1) { cout << "0 0 0\n"; continue; }
    int cnt0 = 1, prv = arr[0];
    for(int i = 1; i < n; i++) 
      if(prv == arr[i]) cnt0++;
    if(3 * cnt0 + 2 > n / 2) { cout << "0 0 0\n"; continue; }
    int cnt1 = cnt0 * 2 + 1; prv = arr[cnt1 - 1];
    for(int i = cnt1; i < n; i++)
      if(prv == arr[i]) cnt1++;
    if(cnt1 > n / 2) { cout << "0 0 0\n"; continue; }
    int cnt2 = cnt1 + 1;
    int ncnt = 0; prv = arr[cnt2 - 1];
    for(int i = cnt2; i < n / 2; i++) {
      if(prv == arr[i]) {
        ncnt++;
      } else {
        cnt2 += ncnt;
        ncnt = 1, prv = arr[i];
      }
    }
    if(arr[n / 2] != prv) cnt2 += ncnt;
    if(cnt2 - cnt1 > cnt0)
      cout << cnt0 << " " << cnt1 - cnt0 << " " << cnt2 - cnt1 << endl;
    else cout << "0 0 0\n";
  }
  return 0;
}

