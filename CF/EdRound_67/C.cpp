#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e3 + 6.66;
int arr[MaxN];
int temp[MaxN];
vector<pair<int, int>> req[2];

int main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int t, l, r; cin >> t >> l >> r;
    req[1 - t].push_back({l - 1, r});
  }
  sort(req[0].begin(), req[0].end());
  sort(req[1].begin(), req[1].end());
  int num = 2e8;
  for(int i = 0; i < req[0].size(); i++) {
    pair<int, int> now = req[0][i];
    while(i < req[0].size() - 1 && req[0][1 + i].first < now.second) {
      now.second = max(now.second, req[0][++i].second);
    }
    fill(arr + now.first, arr + now.second, num -= 2e3);
  }
  int PP = -1;
  for(int i = 0; i < n; i++) {
    if(arr[i]) { PP = -1; continue; }
    if(~PP) arr[i] = --PP;
    else if(i == 0) arr[i] = (PP = 1e9);
    else arr[i] = arr[i - 1] - 1;
  }
  bool ok = true;
  for(auto x : req[1]) {
    bool ok2 = false;
    for(int i = x.first; i < x.second - 1; i++)
      if(arr[i] > arr[i + 1]) ok2 = true;
    if(!ok2) ok = false;
  }
  if(ok) {
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;
  } else cout << "NO" << endl;
  return 0;
}
