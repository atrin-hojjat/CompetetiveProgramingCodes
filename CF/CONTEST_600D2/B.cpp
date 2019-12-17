#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e6 + 6.66;
int mark[MaxN];

int main() {
  int n; cin >> n;
  vector<int> ans;
  int cnt = 0;
  int I = 1, pr = 0;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    if(a > 0) {
      if(mark[a] > 0) {cout << -1 << endl; return 0;}
      if(mark[a] == -I) {cout << -1 << endl; return 0;}
      mark[a] = I, cnt++;
    } else {
      a *= -1;
      if(mark[a] <= 0) {cout << -1 << endl; return 0;}
      mark[a] = -mark[a], cnt--;
    }
    if(cnt == 0) {
      ans.push_back(i + 1 - pr), I++;
      pr = i + 1;
    }
  }
  if(cnt != 0) {cout << -1 << endl; return 0;}
  cout << ans.size() << endl;
  for(auto x : ans) cout << x << " "; cout << endl;
  return 0;
}
