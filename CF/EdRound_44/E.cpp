#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 6.66;
int dp[MAXN];
int arr[MAXN];

struct Segment {
  bool *seg;

  Segment() {
    seg = new bool[MAXN * 4]();
    for(int i = 0; i < MAXN * 4; i++) seg[i] = false;
  }

  void alter(int id, int l, int r, int x, bool val) {
    if(l >= r) return;
    if(l > x || r <= x) return ;
    if(r - l == 1) {
      seg[id] = val;
      return ;
    }
    int mid = l + (r - l) / 2;
    alter(id << 1, l, mid, x, val);
    alter(id << 1 | 1, mid, r, x, val);
    seg[id] = seg[id << 1] || seg[id << 1 |1];
  }

  int get(int id, int l, int r, int b, int e) {
    if(l >= r) return -1;
    if(l >= e || r <= b) return -1;
    if(!seg[id]) return -1;
    if(r - l == 1) return seg[id] ? l : -1;
    int mid = l + (r - l) / 2;
    int cc = get(id << 1 | 1, mid, r, b, e);
    if(!~cc) cc = get(id << 1, l, mid, b, e);
    return cc;
  }

  void alter(int l,bool r) {
    alter(1, 0, MAXN, l, r);
  }

  int get(int l, int r) {
    if(l >= r) return -1;
    return get(1, 0, MAXN, l, r);
  }
} seg;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,k,d; cin >> n >> k >> d;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  deque<pair<int,int>> de;
  int last_st = -1;
  for(int i = 0; i < n; i++) {
    dp[i] = -1;
    int wc = lower_bound(arr, arr + n, arr[i] - d) - arr;
    if(last_st >= wc) dp[i] = 1;
    int wx = seg.get(max(wc - 1, 0), i - k + 1);
    if(~wx) dp[i] = 1,last_st = max(last_st, wx - 1);
    if(i >= k - 1 && wc == 0) last_st = max(last_st,0),dp[i] = 1;
    seg.alter(i, (bool)~dp[i]);
  }
  if(~dp[n-1]) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
