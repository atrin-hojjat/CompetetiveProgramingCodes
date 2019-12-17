#include <bits/stdc++.h>
using namespace std;

const int MaxN = 250 + 25 + 2.5;
const int MaxM = 250000 + 25000;
const int mod = 1e9 + 9;
const int inf = 250 * 1e6 + 250 + 25;
pair<int, int> dis[2][MaxN];
int pths[2][MaxN];
bool mark[MaxN];
struct Edge {
  int a, b;
  int w;

  Edge() { a = b = -1, w = 0; }
  Edge(int a, int b, int w = 1) : a(a), b(b), w(w) { }

  int operator[](int x) {
    return x == a ? b : a;
  }
} eds[MaxM];
vector<int> edges[MaxN];

istream& operator>>(istream&x, Edge& w) {
  x >> w.a >> w.b >> w.w;
  w.a--, w.b--;
  return x;
}

void norm(int&x) {
  while(x >= mod) x -= mod;
}

int& add(int&x, int y) {
  norm(x), norm(y);
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int& sub(int&x, int y) {
  norm(x), norm(y);
  x -= mod;
  if(x < 0) x += mod;
  return x;
}

void dijkstra(int source, int n, pair<int, int>*dis, int*pths) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for(int i = 0; i < n; i++) dis[i] = {inf, -1}, pths[i] = 0;
  memset(mark, 0, sizeof mark);
  dis[source] = {0, -1}, pths[source] = 1;
  pq.push({dis[source].first, source});
  while(pq.size()) {
    pair<int, int> now = pq.top();
    swap(now.first, now.second);
    pq.pop();
    if(mark[now.first]) continue;
    mark[now.first] = true;
    for(auto x : edges[now.first]) {
      int d = now.second + eds[x].w;
      int other = eds[x][now.first];
      if(d < dis[other].first) {
        pths[other] = pths[now.first];
        dis[other] = {d, x};
        pq.push({dis[other].first, other});
      } else if(d == dis[other].first) add(pths[other], pths[now.first]);
    }
  }
}

int main() {
#ifdef Atrin
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
#else
  freopen("rblock.in", "rt", stdin);
  freopen("rblock.out", "wt", stdout);
#endif
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> eds[i];
    edges[eds[i].a].push_back(i);
    edges[eds[i].b].push_back(i);
  }
  dijkstra(0, n, &dis[0][0], &pths[0][0]);
  int mx = dis[0][n - 1].first;
  int now = n - 1;
  while(now) {
    int ed = dis[0][now].second;
    eds[ed].w <<= 1;
    dijkstra(0, n, &dis[1][0], &pths[1][0]);
    mx = max(mx, dis[1][n - 1].first);
    eds[ed].w >>= 1;
    now = eds[ed][now];
  }
  cout << mx - dis[0][n - 1].first << endl;
  return 0;
}
