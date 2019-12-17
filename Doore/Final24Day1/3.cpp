#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int Sq = 529;

struct Query {
  int a, b, t; char type;
};

map<int, int> cmp;
vector<Query> ques;
int mp[1 + MaxN / Sq][111];
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
    if(mp[i][now]) now = mp[i][now];
  for(int i = pos * Sq; i < t; i++)
    if(now == q[i].first)
     now = q[i].second;
  return now;
}

void change(int t, int a, int b) {
  int pos = t / Sq;
  vector<int> sts;
  for(int i = min(MaxN - 1, (pos + 1) * Sq - 1); i > pos * Sq - 1; --i)
  {
    if(q[i].first) sts.push_back(q[i].first);
  }
  for(auto x : sts) mp[pos][x] = 0;
  q[t] = {a, b};
  for(int i = min(MaxN - 1, (pos + 1) * Sq - 1); i > pos * Sq - 1; --i)
  {
    if(!q[i].first) continue;
    if(mp[pos][q[i].second])
      mp[pos][q[i].first] = mp[pos][q[i].second];
    else mp[pos][q[i].first] = q[i].second;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int Q; cin >> Q;
  if(Q <= 1e4) {
    set<pair<int, pair<int, int>>> s;
    for(int i = 0; i < Q; i++) {
      char type; cin >> type;
      if(type == '~') 
      {
        int a, b, c;
        cin >> a >> b >> b;
        s.insert({a, {b, c}});
      } else {
        int t; cin >> t;
        int now = 1;
        for(auto x : s) {
          if(x.first > t) break;
          if(x.second.first == now) now = x.second.second;
        }
        cout << now << endl;
      }
    }
    return 0;
  }
  for(int i = 0; i < Q; i++) {
    char type; cin >> type;
    Query q;
    q.type = type;
    if(q.type == '~') {
      cin >> q.t >> q.a >> q.b;
      if(q.a > 100 || q.b > 100) return 0;
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
