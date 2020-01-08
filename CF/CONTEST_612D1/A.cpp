#include <iostream>
#include <set>
using namespace std;

const int MaxN = 100 + 10 + 1;
int arr[MaxN];
int has[MaxN];

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) has[arr[i]] = 1;
  int st = -1;
  int ans = 0;
  multiset<pair<int, int>> S[4];
  int cnt[2] = {0, 0};
  for(int i = 0; i < n; i++) {
    if(!arr[i]) continue;
    if(st == -1 || arr[i] % 2 == arr[st] % 2) {
      S[2 * (st == -1) + arr[i] % 2].insert({i - st - 1, st == -1});
    } else ans++;
    st = i;
  }
  if(~st) {
    S[2 + arr[st] % 2].insert({n - st - 1, 1});
  } else {
    cout << 1 - (n == 1) << endl;
    return 0;
  }
  for(int i = 1; i <= n; i++) if(!has[i]) cnt[i % 2]++;
  for(int i = 0; i < 4; i++)
    while(S[i].size() && S[i].begin()->first <= cnt[i % 2]) {
      cnt[i % 2] -= S[i].begin()->first;
      S[i].erase(S[i].begin());
    }
  cout << ans + 2 * (S[0].size() + S[1].size()) + S[2].size() + S[3].size() << endl;
  return 0;
}
