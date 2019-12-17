#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
int ch[MaxN];
set<pair<int, int>> s;
map<int, bool> mark;
map<int, queue<int>> qs;

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x, y; scanf("%d %d", &x, &y);
    s.insert({x, i});
    s.insert({y, i});
  }
  int ans = 0;
  int rem = n;
  for(auto x : s) {
    if(mark[x.first]) {
      qs[x.first].push(x.second);
    } else {
      if(ch[x.second]) {
        if(qs.count(ch[x.second]) == 0) continue;
        while(qs[ch[x.second]].size() && ch[qs[ch[x.second]].front()]) qs[x.first].pop();
        if(qs[ch[x.second]].size()) {
          ch[qs[ch[x.second]].front()] = ch[x.second];
          ch[x.second] = x.first;
          mark[x.first] = true;
          rem--;
        }
      } else ch[x.second] = x.first, mark[x.first] = true, rem--;
    }
    if(rem == 0) {
      ans = x.first;
      break;
    }
  }
  if(rem > 0) ans = -1;
  printf("%d\n", ans);
  return 0;
}
