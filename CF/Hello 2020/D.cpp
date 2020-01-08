#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 4e5 + 6.66;

struct Segment {
  int seg[MaxN * 4];

  Segment() {
    memset(seg, 0, sizeof seg);
  }

  void add(int id, int l, int r, int u, int v) {
    if(l >= r) return ;
    if(l > u || r <= u) return ;
    if(l + 1 == r) {
      seg[id] += v;
      return ;
    }
    int mid = l + (r - l) / 2;
    add(id << 1, l, mid, u, v);
    add(id << 1 | 1, mid, r, u, v);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }

  void add(int l, int x) {
    add(1, 0, MaxN, l, x);
  }

  int get(int id, int l, int r, int b, int e) {
    if(l >= r) return 0;
    if(l >= e || b >= r) return 0;
    if(l >= b && r <= e) return seg[id];
    int mid = l + (r - l) / 2;
    return get(id << 1, l, mid, b, e) + get(id << 1 | 1, mid, r, b, e);
  }

  int get(int l, int r) { return get(1, 0, MaxN, l, r); }
  
} Left, Right;

pair<int, int> AA[MaxN], BA[MaxN];
vector<int> ADD[MaxN], DEL[MaxN];
map<int, int> m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  pair<int, int> * A = AA, *B = BA;
  for(int i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second >> B[i].first >> B[i].second;
    m[A[i].first] = m[B[i].first] = m[A[i].second] = m[B[i].second];
  }
  int I = 2;
  for(auto &x : m) x.second = I++;
  for(int II = 0; II < 2; II++) {
    for(int i = 0; i < n; i++) {
      ADD[m[A[i].first]].push_back(i);
      DEL[m[A[i].second]].push_back(i);
    }
    for(int i = 0; i < MaxN; i++) {
      for(auto u : ADD[i])  {
        int t = Left.get(0, m[B[u].first]) + Right.get(m[B[u].second] + 1, MaxN);
        if(t > 0) {
          cout << "NO" << endl;
          return 0;
        }
        Left.add(m[B[u].second], 1);
        Right.add(m[B[u].first], 1);
      }
      for(auto u : DEL[i]) {
        Left.add(m[B[u].second], -1);
        Right.add(m[B[u].first], -1);
      }
    }
    for(int i = 0; i < MaxN; i++) DEL[i].clear(), ADD[i].clear();
    A = BA, B = AA;
  }
  cout << "YES" << endl;
  return 0;
}
