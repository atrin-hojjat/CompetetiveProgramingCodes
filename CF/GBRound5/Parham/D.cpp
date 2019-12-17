#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

const int MAXn = 3e5 + 100;
const int inf = 1e9 + 7;
int mx = 0, mn = inf;
int seg[MAXn * 4], val[MAXn * 4];
int seg2[MAXn * 4];
int arr[2 * MAXn], dp[2 * MAXn];
int ans[2 * MAXn];
int n;
map<int, int> mp;

void add(int idx, int l, int r, int b, int x) {
  if(l >= r) return ;
  if(l > b || r <= b) return ;
  if(l + 1 == r) {
    seg[idx] = x;
    return ;
  }
  int mid = l + (r - l) / 2;
  add(idx << 1, l, mid, b, x);
  add(idx << 1 | 1, mid, r, b, x);
  seg[idx] = min(seg[idx << 1], seg[idx << 1 | 1]);
}

int get(int idx, int l, int r, int b, int e) {
  if(l >= r) return inf;
  if(l >= e || r <= b) return inf;
  if(l >= b && r <= e) return seg[idx];
  int mid = l + (r - l) / 2;
  return min(get(idx << 1, l, mid, b, e), get(idx << 1 | 1, mid, r, b, e));
}

void build(int idx, int l, int r) {
  if(l >= r) return ;
  if(l + 1 == r) {
    seg2[idx] = inf;
    return ;
  }
  seg2[idx] = inf;
  int mid = l + (r - l) / 2;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid, r);
}

void add_min(int idx, int l,int r, int x, int val) {
  if(l >= r) return ;
  if(l > x || r <= x) return ;
  if(l + 1 == r) {
    seg2[idx] = val;
    return ;
  }
  int mid = l + (r - l) / 2;
  add_min(idx << 1, l, mid, x, val);
  add_min(idx << 1 | 1, mid, r, x, val);
  seg2[idx] = min(seg2[idx << 1], seg2[idx << 1 | 1]);
}

int get_min(int idx, int l, int r, int b, int e) {
  if(l >= r) return inf;
  if(l >= e || r <= b) return inf;
  if(l >= b && r <= e) return seg2[idx];
  int mid = l + (r - l) / 2;
  return min(get_min(idx << 1, l, mid, b, e), get_min(idx << 1 | 1, mid, r, b, e));
}

int main() {
  cin >> n;
  memset(seg, 63, sizeof seg);
  for(int i = 0; i < n; ++i) cin >> arr[i];
  for(int i = 0; i < n; ++i) arr[2 * n + i] = arr[n + i] = arr[i];
  for(int i = 0; i < n; ++i) mx = max(mx, arr[i]), mn = min(mn, arr[i]);
  if(mx <= 2 * mn) {
    for(int i = 0; i < n; ++i) cout << -1 << " "; cout << endl;
    return 0;
  }
  build(1, 0, 2 * n);
  ans[3 * n - 1] = 3 * n;
  for(int i = 0; i < n; ++i) mp[2 * arr[i]] = mp[arr[i]] = 0;
  int II = 0;
  for(auto&x : mp) x.second = ++II;
  add_min(1, 0, 2 * n, mp[2 * arr[3 * n - 1]], 3 * n - 1);
  add(1, 0, 3 * n, 3 * n - 1, ans[3 * n - 1]);
  for(int i = 3 * n - 2; i > -1; --i) {
    int mm = get_min(1, 0, 2 * n, 0, mp[arr[i]]);
    add_min(1, 0, 2 * n, mp[2 * arr[i]], i);
    ans[i] = min(mm, get(1, 0, 3 * n, 1 + i, 3 * n));
    add(1, 0, 3 * n, i, ans[i]);
  }
  for(int i = 0; i < n; i++) cout << ans[i] - i << " "; cout << endl;
  return 0;
}
