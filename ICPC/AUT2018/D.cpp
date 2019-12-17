#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
const int MaxN = 5000 + 200 + 20 + 2;
int ans[MaxN][MaxN];
int arr[MaxN];

int main() {
  int n, m, k; cin >> n >> m >> k;
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  if(m == 0) {
    //cout << 1 << endl;
    cout << 0 << endl;
    //cout << (k == m) << endl;
    return 0;
  } else if(m == 1) {
    int ans = 1;
    for(int i = 0; i < n; i++) ans = (1ll * ans * arr[i] % mod);
    cout << ans << endl;
    return 0;
  }
  for(int i = 0; i <= arr[0]; i++)
    ans[0][i % m]++;
  for(int i = 1; i < n; i++) {
    int sum = 0;
    int en = 0, st = (-arr[i] + 500000ll * m ) % m;
    for(int j = 0; j <= arr[i]; j++) 
      sum = (0ll + ans[i - 1][(500000ll * m - j) % m] + sum) % mod;
    for(int j = 0; j < m; j++) {
      ans[i][j] = sum;
      en = (en + 1) % m;
      sum = (0ll + sum + mod - ans[i - 1][st] + ans[i - 1][en]) % mod;
      st = (st + 1) % m;
    }
  }
//  for(int i = 0; i < n; i++, cout << endl)
//    for(int j = 0; j < m; j++) cout << ans[i][j] << " ";
  cout << ans[n - 1][k] << endl;
  return 0;
}
