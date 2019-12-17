#include <bits/stdc++.h>
using namespace std;

const int MaxN = 11;
const int mod = 1e6 + 3;
int arr[MaxN];

int main() {
  int ans = 0;
  int n, k; cin >> n >> k;
  for(int i = 0; i < n; i++) arr[i] = i;
  do {
    int mx = 0;
    for(int i = 0; i < n; i++) {
      int c = 0;
      for(int j = i + 1; j < n; j++) 
        if(arr[j] < arr[i]) c++;
      mx = max(mx, c);
      if(c > k) break;
    }
    if(mx <= k) (ans += 1) %= mod;
  } while(next_permutation(arr, arr + n));
  cout << ans << endl;
  return 0;
}
