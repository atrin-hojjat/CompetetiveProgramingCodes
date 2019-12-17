#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MaxN = 1e5 + 6.66;

struct Segment {
  int upd[(int) (1e5 + 6.66) * 4];
  int cnt[26][(int) (1e5 + 6.66) * 4];
  int sz[(int) (1e5 + 6.66) * 4];
  
  Segment() {
    memset(upd, 0, sizeof upd);
    for(int i = 0; i < 26; i++)
      for(int j = 0; j < 4 * MaxN; j++) cnt[i][j] = 0;
  }

  void push(int id, int l, int r, int *c, int stat) {
    upd[id] = stat;
    int szz = r - l;
    for(int i = 0; i < 26; i++) {
      int I = i;
      if(stat < 0) I = 25 - i;
      int add = min(szz, c[I]);
      c[I] -= add;
      szz -= add;
      cnt[I][id] = add;
    }
  }

  void just_add(int id, int l, int r, string& s) {
    if(l >= r) return ;
    if(l + 1 == r) {
      if(l < s.size()) cnt[s[l] - 'a'][id] = 1;
      return ;
    }
    int mid = l + (r - l) / 2;
    just_add(id << 1, l, mid, s);
    just_add(id << 1 | 1, mid, r, s);
    for(int i = 0; i < 26; i++)
      cnt[i][id] = cnt[i][id << 1] + cnt[i][id << 1 | 1];
  }

  void push_down(int id, int l, int mid, int r) {
    if(upd[id] == 0) return ;
    int c[26];
    for(int i = 0; i < 26; i++) c[i] = cnt[i][id];
    push(id << 1, l, mid, c, upd[id]);
    push(id << 1 | 1, mid, r, c, upd[id]);
    upd[id] = 0;
  }

  void get(int id, int l, int r, int b, int e, int *c, vector<int>& v) {
    if(l >= r) return;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      for(int i = 0; i < 26; i++) c[i] += cnt[i][id];
      v.push_back(id);
      sz[id] = r - l;
      return ;
    }
    int mid = l + (r - l) / 2;
    push_down(id, l, mid, r);
    get(id << 1, l, mid, b, e, c, v);
    get(id << 1 | 1, mid, r, b, e, c, v);
  }

  void go_up(int id, int l, int r, int b, int e) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) return ;
    int mid = l + (r - l) / 2;
    go_up(id << 1, l, mid, b, e);
    go_up(id << 1 | 1, mid, r, b, e);
    for(int i = 0; i < 26; i++)
      cnt[i][id] = cnt[i][id << 1] + cnt[i][id << 1 | 1];
  }

  void alter(int l, int r, int st) {
    int c[26] = {0};
    vector<int> v;
    get(1, 0, MaxN, l, r, c, v);
    int i = 0;
    for(auto x : v) {
      upd[x] = st;
      int id = x;
      for(int i = 0; i < 26; i++) cnt[i][id] = 0;
      for(int i = 0; sz[id] && i < 26; i++) {
        int I = i;
        if(st < 0) I = 25 - i;
        int add = min(sz[id], c[I]);
        cnt[I][id] = add;
        c[I] -= add;
        sz[id] -= add;
        if(sz[id] == 0) break;
      }
    }
    go_up(1, 0, MaxN, l, r);
  }

  void push_all_down(int id = 1, int l = 0, int r = MaxN) {
    if(l >= r) return ;
    if(l + 1 == r) {
      for(int i = 0; i < 26; i++) {
        if(cnt[i][id]) cout << (char) ('a' + i);
      }
      return ;
    }
    int mid = l + (r - l) / 2;
    push_down(id, l, mid, r);
    push_all_down(id << 1, l, mid);
    push_all_down(id << 1 | 1, mid, r);
  }
} seg;

int main() {
  int n, q; cin >> n >> q;
  string str; cin >> str;
  seg.just_add(1, 0, MaxN, str);
  while(q--) {
    int l, r, k; cin >> l >> r >> k;
    l--;
    seg.alter(l, r, k * 2 - 1);
  }
  seg.push_all_down();
  cout << endl;
  return 0;
}
