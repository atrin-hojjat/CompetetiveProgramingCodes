#include <iostream>
#include <math.h>
#include <queue>
#include <iomanip>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
long double dp[MaxN];
long double radia[MaxN];
pair<int, int> cnt[MaxN];
bool mark[MaxN];

int main() {
  int N; cin >> N;
  for(int i = 1; i < N + 1; i++) cin >> radia[i] >> cnt[i].first >> cnt[i].second;
  for(int i = 1; i < N + 1; i++) dp[i] = 6e6 + 6;
  priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> s;
  s.push({0, 0});
  while(s.size()) {
    auto [d, x] = s.top();
    s.pop();
    if(x == N) break;
    mark[x] = true;
    for(int i = 0; i <= N; i++)
    {
      if(mark[i]) continue;
      long double dx = cnt[x].first - cnt[i].first;
      long double dy = cnt[x].second - cnt[i].second;
      long double dis = d + max(sqrtl(dx * dx + dy * dy) - radia[x] - radia[i], 0.l);
      if(dis < dp[i]) {
        dp[i] = dis;
        s.push({dis, i});
      }
    }
  }
  cout << fixed << setprecision(10) << dp[N] << endl;
  return 0;
}
