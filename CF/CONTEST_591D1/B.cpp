#include <iostream>
#include <set>
using namespace std;

const int MaxN = 3e5 + 6.66;
int a[MaxN], cnt[MaxN], Ans[MaxN];
bool mark[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int Q; cin >> Q;
  while(Q--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i <= 3 + n; i++) cnt[i] = 0;
    for(int i = 0; i <= 3 + n; i++) mark[i] = 0;
    int CNT = 0;
    set<int> s;
    for(int i = 0; i < n; i++) {
      if(cnt[a[i]] == 0) CNT++, s.insert(-a[i]);
      cnt[a[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(!mark[a[i]]) {
        auto x = s.lower_bound(-a[i] + 1);
        int t = 1;
        if(s.end() != x && cnt[-*x] == 0) {
          t += Ans[-*x];
        }
        Ans[a[i]] = t;
        mark[a[i]] = true;
      }
      if(--cnt[a[i]] == 0) ans = max(ans, Ans[a[i]]);
    }
    cout << CNT - ans << endl;
  }
  return 0;
}
