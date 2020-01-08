#include <iostream>
#include <map>
using namespace std;

const int MaxN = 2e5 + 6.66;
map<int, int> M[MaxN];
int arr[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> arr[i];
  long long Ans = 0;
  for(int i = 0; i <= n; i++) Ans += arr[i];
  int q; cin >> q;
  while(q--) {
    int a, b, c; cin >> a >> b >> c;
    if(M[a][b]) {
      arr[M[a][b]]++;
      if(arr[M[a][b]] > 0) Ans++;
    }
    M[a][b] = c;
    arr[c]--;
    if(arr[c] >= 0) Ans--;
    cout << max(1ll, Ans) << "\n";
  }
  return 0;
}
