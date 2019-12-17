#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
int d[MaxN];
int out_d[MaxN];
vector<int> rev[MaxN];

int main() {
#ifndef Atrin
  freopen("grand.in", "rt", stdin);
  freopen("grand.out", "wt", stdout);
#endif
  while(true) {
    int n; cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; i++)
      rev[i].clear();
    fill(out_d, out_d + n, 0);
    for(int i = 0; i < n; i++) {
      cin >> d[i];
      if(d[i] > n) d[i] = n;
    }
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      out_d[x]++;
      rev[y].push_back(x);
    }
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++)
      if(out_d[i] == 0) pq.push({d[i], i});
    int now = n;
    int mx = 0;
    stack<int> ans;
    while(pq.size()) {
      int v = pq.top().second;
      ans.push(v);
      mx = max(mx, now - pq.top().first);
      now--;
      pq.pop();
      for(auto x : rev[v])
        if(--out_d[x] == 0) 
          pq.push({d[x], x});
    }
    cout << mx << endl;
    while(ans.size()) {
      cout << 1 + ans.top() << " ";
      ans.pop();
    }
    cout << endl;
  }
  return 0;
}
