#include <iostream>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 2e5 + 6.66 + 10;
const int Log = 22;
const int inf = 1e9 + 7;
int S[MaxN];
pair<int, int> hers[MaxN];
int mons[MaxN];
map<int, int> P;
int dp[MaxN];
int sparse[Log][MaxN];

int get(int l, int r) {
  int x = 0;
  while((1 << x) <= r - l) x++; x--;
  return max(sparse[x][l], sparse[x][r - (1 << x)]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> mons[i];
    int m; cin >> m;
    P.clear();
    for(int i = 0; i < m; i++) cin >> hers[i].first >> hers[i].second;
    for(int i = 0; i <= n + 5; i++) S[i] = 0, dp[i] = 0;
    for(int i = 0; i < m; i++) S[hers[i].second] = max(S[hers[i].second], hers[i].first);
    for(int i = n; i > -1; i--) S[i] = max(S[i], S[i + 1]);
    for(int i = 0; i < n; i++) {
      sparse[0][i] = mons[i];
    }
    for(int i = 1; i < Log; i++)
      for(int j = 0; j < n; j++)
        if(j + (1 << (i - 1)) <= n) sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        else sparse[i][j] = sparse[i - 1][j];
    for(int i = n - 1; i > -1; i--) {
      int L = i, R = n - 1;
      while(L < R) {
        int mid = L + (R - L + 1) / 2;
        if(get(i, mid + 1) <= S[mid - i + 1]) L = mid;
        else R = mid - 1;
      }
      if(R < i || get(i, 1 + R) > S[R - i + 1]) dp[i] = inf;
      else dp[i] = 1 + dp[R + 1];
    }
    cout << (dp[0] >= inf ? -1 : dp[0]) << endl;
    for(int i = 0; i < Log; i++)
      for(int j = 0; j <= 5 + n; j++) sparse[i][j] = 0;
  }
  return 0;
}
