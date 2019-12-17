#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int Sq = 529;

struct Query {
  int a, b, t; char type;
};

map<int, int> cmp;
vector<Query> ques;
unordered_map<int, int> mp[10 + MaxN / Sq];
pair<int, int> q[1000 + Sq * Sq];

void compress(int N) {
  for(auto x : ques) cmp[x.t] = true;
  int I = 0;
  for(auto &w : cmp) w.second = I++;
}

int ask(int t) {
  int pos = t / Sq;
  int now = 1;
  for(int i = 0; i < pos; i++)
    if(mp[i].count(now)) now = mp[i][now];
  for(int i = pos * Sq; i < t; i++)
    if(now == q[i].first)
     now = q[i].second;
  return now;
}

void change(int t, int a, int b) {
  int pos = t / Sq;
  q[t] = {a, b};
  mp[pos].clear();
  for(int i = min(MaxN - 1, (pos + 1) * Sq - 1); i > pos * Sq - 1; --i)
  {
    if(!q[i].first) continue;
    if(mp[pos].count(q[i].second))
      mp[pos][q[i].first] = mp[pos][q[i].second];
    else mp[pos][q[i].first] = q[i].second;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int Q; cin >> Q;
  for(int i = 0; i < Q; i++) {
    char type; cin >> type;
    Query q;
    q.type = type;
    if(q.type == '~') {
      cin >> q.t >> q.a >> q.b;
    } else cin >> q.t;
    ques.push_back(q);
  }
  compress(Q);
  for(auto x : ques) {
    if(x.type == '?') {
      cout << ask(cmp[x.t]) << endl;
    } else {
      change(cmp[x.t], x.a, x.b);
    }
  }
  return 0;
}
