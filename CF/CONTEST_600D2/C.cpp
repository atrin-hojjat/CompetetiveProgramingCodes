#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

const int MaxN = 2e5 + 6.66;
int arr[MaxN];
int ans[MaxN];
int Nsum[MaxN];
int sum[MaxN];

signed main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int Z = 1;
  Nsum[0] = arr[0];
  for(int i = 1; i < n; i++) Nsum[i] = Nsum[i - 1] + arr[i];
  for(int i = m; i < n; i++) sum[i] = sum[i - m] + arr[i - m];
  for(int i = 0; i < n; i++) {
    if(i > 0) ans[i] = ans[i - 1];
    ans[i] += arr[i] + sum[i];
//    if(i % m == 0) ans[i] += Nsum[i - m] - sum[i];
  }
  for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
  return 0;
}
