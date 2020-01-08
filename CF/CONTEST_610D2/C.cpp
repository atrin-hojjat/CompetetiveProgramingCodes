#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define int long long
const int MaxN = 2e5 + 6.66;
int diff[MaxN];
int tim[MaxN];

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int tests; cin >> tests;
  while(tests--) {
    int n, T, a, b; cin >> n >> T >> a >> b;
    for(int i = 0; i < n; i++) cin >> diff[i];
    set<int> S; S.insert(0), S.insert(T);
    for(int i = 0; i < n; i++) {
      cin >> tim[i];
      S.insert(tim[i]);
      S.insert(tim[i] - 1);
    }
    int ptr = 0, as = 0, bs = 0;
    vector<int> srt;
    for(int i = 0; i < n; i++) srt.push_back(i);
    for(int i = 0; i < n; i++)
      if(diff[i] == 0) as++;
      else bs++;
    sort(srt.begin(), srt.end(), [] (int i, int j) { return tim[i] < tim[j];});
    int sum = 0;
    int tot = 0;
    for(int now : S) {
      while(ptr < srt.size() && tim[srt[ptr]] == now) {
        if(diff[srt[ptr]]) bs--, sum += b;
        else as--, sum += a;
        ptr++;
      }
      if(sum > now) {
        continue;
      }
      int left = now - sum;
      int Ans = ptr;
      if(left / a < as) Ans += left / a;
      else Ans += as;
      left -= min(left / a, as) * a;
      if(left / b < bs) Ans += left / b;
      else Ans += bs;
      left -= min(left / b, bs) * b;
      tot = max(tot, Ans);
    }
    cout << tot << endl;
  }
  return 0;
}
