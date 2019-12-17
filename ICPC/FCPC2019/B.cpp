#include <iostream>
#include <map>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int inf = 1e9 + 7;
pair<int, int> pts[MaxN];
map<int, long long> val[2];
map<int, long long> orval[2];
char ans[MaxN];
long long Val[200];

int main() {
  int n, m, r, b; cin >> n >> m >> r >> b;
  char cheap = 'r', exs = 'b';
  Val[cheap] = r, Val[exs] = b;
  if(r > b) swap(cheap, exs);
  for(int i = 0; i < n; i++) {
    cin >> pts[i].first >> pts[i].second;
  }
  for(int i = 0; i < m; i++) {
    long long t, a, l;
    cin >> t >> a >> l;
    if(orval[t - 1].count(a)) {
      orval[t - 1][a] = min(orval[t - 1][a], l);
    } else {
      orval[t - 1][a] = l;
    }
    val[t - 1][a] = 0;
  }
  for(int i = 0; i < n; i++) {
    if(orval[0].count(pts[i].first) == 0) orval[0][pts[i].first] = inf;
    if(orval[1].count(pts[i].second) == 0) orval[1][pts[i].second] = inf;
  }
  long long Ans = 0;
  for(int i = 0; i < n; i++) {
    int A = val[0][pts[i].first], B = val[1][pts[i].second];
    if(A >= orval[0][pts[i].first] || B >= orval[1][pts[i].second]) {
      val[0][pts[i].first]--, val[1][pts[i].second]--;
      ans[i] = exs;
      Ans += Val[exs];
    } else {
      val[0][pts[i].first]++, val[1][pts[i].second]++;
      ans[i] = cheap;
      Ans += Val[cheap];
    }
  }
  for(auto x : val[0]) if(abs(x.second) > orval[0][x.first]) {cout << "-1" << endl; return 0;}
  for(auto x : val[1]) if(abs(x.second) > orval[1][x.first]) {cout << "-1" << endl; return 0;}
  cout << Ans << endl;
  for(int i = 0; i < n; i++) cout << ans[i]; cout << endl;
  return 0;
}
