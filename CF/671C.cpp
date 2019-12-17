#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6.66;
vector<int> divs [ MAXN ];
int arr[MAXN];
int first_pos[MAXN];
int last_pos[MAXN];

struct Segment { 
  const int Max = ( 2e5 + 6.66 ) ;
  long long *sum;
  int  *Mn, *Mx, *laz;

  Segment ( ) { 
    sum = new long long [ Max * 4 ] ( ) ;
    Mx = new int [ Max * 4 ] ( ) ;
    Mn = new int [ Max * 4 ] ( ) ;
    laz = new int [ Max * 4] ( ) ;
    for(int i = 0; i<Max*4; i++) laz[i] = -1;
  }

  void apply(int id, int l, int r, int val) {
    Mx[id] = Mn[id] = val;
    sum[id] = 1LL * ( r - l ) * val;
    laz[id] = val;
  }

  void pushdown(int id, int l, int r) {
    if(!~laz[id]) return ;
    int mid = l + (r - l) / 2;
    apply(id << 1, l, mid, laz[id]);
    apply(id << 1 | 1, mid, r, laz[id]);
    laz[id] = -1;
  }
  
  void max_interval(int id, int l, int r, int b, int e, int val) {
    if(l >= e || r <= b || val <= Mn[id]) return ;
    if(l >= b && r <= e && Mx[id] <= val) {
      apply(id, l, r, val);
      return ;
    }
    pushdown(id, l, r);
    int mid = l + (r - l) / 2;
    max_interval(id << 1, l, mid, b, e, val);
    max_interval(id << 1 | 1, mid, r, b, e, val);
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
    Mn[id] = min(Mn[id << 1], Mn[id << 1 | 1]);
    Mx[id] = max(Mx[id << 1], Mx[id << 1 | 1]);
  }

  void max_interval(int l, int r, int val) {
    max_interval(1, 0, Max, l, r, val);
  }

  long long get_sum(int id, int l, int r, int b, int e) {
    if(l >= e || r <= b) return 0;
    if(l >= b && r <= e) return sum[id];
    pushdown(id, l, r);
    int mid = l + (r - l) / 2;
    return get_sum(id << 1, l, mid, b, e) + get_sum(id << 1 | 1, mid, r, b, e);
  }

  long long get_sum(int l, int r) {
    return get_sum(1, 0, Max, l, r);
  }
} seg;

void init() {
  for(int i = 1; i<MAXN; i++)
    for(int j = i; j<MAXN; j += i)
      divs[j].push_back(i);
  for(int i = 1; i<MAXN; i++)
    reverse(divs[i].begin(), divs[i].end());
}

int main() {
  init() ;
  int n;scanf("%d", &n);
  for(int i = 0; i<n; i++) scanf("%d",arr + i);
  for(int i = n-1; i>-1; --i)
    for(auto x : divs[arr[i]])
      first_pos[x] = i;
  for(int i = 0; i<n; i++)
    for(auto x : divs[arr[i]])
      last_pos[x] = i;
  long long ans = 0;
  long long mx = 0;
  for(int i = 0; i<n; i++)
  {
    for(auto x : divs[arr[i]])
      if(first_pos[x] < i)
      {
        mx = max(mx, ( long long ) x);
        break;
      }
    seg.max_interval(i,n,mx);
    if(i < n - 1 ) ans += mx;
  }
  mx = 0;
  for(int i = n-1; i>-1; --i) {
    for(auto x : divs[arr[i]])
      if(last_pos[x] > i)
      {
        mx = max(mx, ( long long ) x);
        break;
      }
    int last = i;
    for(auto x : divs[arr[i]])
      if(first_pos[x] < last)
      {
        seg.max_interval(first_pos[x],last,x);
        last = first_pos[x];
      }
    seg.max_interval(0,i,mx);
    ans += seg.get_sum(0, max(i-1, 0));
    if(i > 0) ans += mx;
  }
  printf("%lld\n", ans);
  return 0;
}
