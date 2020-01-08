#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 2e5 + 6.66;
int dp[MaxN];
int arr[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int n, p, k; cin >> n >> p >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    dp[0] = arr[0];
    for(int i = 1; i < k - 1; i++) dp[i] = arr[i] + dp[i - 1];
    dp[k - 1] = arr[k - 1];
    for(int i = k; i < n; i++) dp[i] = arr[i] + dp[i - k];
    int ans = -1;
    for(int i = 0; i < n; i++)
      if(dp[i] <= p) ans = i;
    cout << 1 + ans << endl;
  }
  return 0;
}
