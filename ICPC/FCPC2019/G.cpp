#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int MaxN = 3e5 + 6.66;
int s[MaxN];
int f[MaxN];
int val[MaxN];
int ans[MaxN];
int sr[MaxN];
pair<int, int> UPD[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) sr[i] = i;
    for(int i = 0; i < m; i++) cin >> s[i] >> f[i] >> val[i];
    for(int i = 0; i < n + 1; i++) ans[i] = 0;
    sort(sr, sr + m, [] (int i, int j) { return val[i] < val[j]; });
    int prv = -1;
    int Ans = 0;
    int S = 0, E = 0;
    for(int I = 0; I < m; I++) {
      int i = sr[I];
      if(val[i] != prv) {
        while(S < E) {
          ans[UPD[S].first] = max(ans[UPD[S].first], UPD[S].second);
          S++;
        }
      }
      prv = val[i];
      Ans = max(Ans, ans[s[i]] + 1);
      UPD[E++] = {f[i], ans[s[i]] + 1};
    }
    cout << Ans << endl;
  }
  return 0;
}
