#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int MaxN = 4e5 + 6.66;
int cnt_cnt[MaxN];
map<int, int> cnt;
int arr[MaxN];
priority_queue<pair<int, int>> ordered;

int used = 1e9+ 7, CNT = 0;
int num = -1;
int next(int I) {
  if(used >= I || used >= CNT) {
    auto x = ordered.top();;
    ordered.pop();
    num = x.second;
    CNT = x.first;
//    cout << " " << x.first << " " << x.second << endl;
    used = 0;
  }
  used++;
  return num;
}

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) cnt[arr[i]]++;
  for(auto x : cnt) cnt_cnt[x.second]++;
  for(auto x : cnt) ordered.push({x.second, x.first});
  int C = cnt.size(), X = 0;
  pair<int, pair<int, int>> ans = {1, {1, 1}};
  for(int i = 1; i <= cnt.size(); i++) {
    int tot = C / i;
    if(tot < i) break;
    tot = min(tot, (int) cnt.size());
//    cout << i << " " << tot << " " << i * tot << endl;
    ans = max({i * tot, {tot, i}}, ans);
    X += cnt_cnt[i];
    C += cnt.size() - X;
  }
  cout << ans.first << endl;
  cout << ans.second.second << " " << ans.second.first << endl;
  vector<int> ret[ans.second.second];
  for(int i = 0; i < ans.second.second; i++) ret[i].resize(ans.second.first);
  for(int i = 0; i < ans.second.first; i++)
  {
    int I = i, J = 0;
    for(int j = 0; j < ans.second.second; j++, I = (I + 1) % ans.second.first, J++) {
      ret[J][I] = next(min(ans.second.first, ans.second.second));
    }
  }
  for(int i = 0; i < ans.second.second; i++, cout << endl)
    for(int j = 0; j < ans.second.first; j++) cout << ret[i][j] << " ";
  return 0;
}
