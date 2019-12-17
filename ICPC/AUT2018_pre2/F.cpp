#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Segment { 
  int X[(int) (1e6 + 6.66)];
  int sum[(int) (1e6 + 6.66)], sumg[(int) (1e6 + 6.66)];
  int N = -1;
  
  Segment() {

  }

  void build(int id, int l, int r, int* i) {
    if(l >= r) return ;
    if(r - l == 1) {
      sum[id] = i[l];
      sumg[id] = 0;
      return ;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid, i);
    build(id << 1 | 1, mid, r, i);
    sumg[id] = 0;
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
  }

  void build(int n, int * x) {
    N = n;
    build(1, 0, n, x);
  }

  inline void push_down(int x) {
    X[x] ^= 1;
    sumg[x] = sum[x] - sumg[x];
  }

  inline void push(int x) {
    if(X[x] == 0) return ;
    push_down(x << 1);
    push_down(x << 1 | 1);
    X[x] = 0;
  }

  void add(int id, int l, int r, int b, int e) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      push_down(id);
      return ;
    }
    push(id);
    int mid = l + (r - l) / 2;
    add(id << 1, l, mid, b, e);
    add(id << 1 | 1, mid, r, b, e);
    sumg[id] = sumg[id << 1] + sumg[id << 1 | 1];
  }
  
  int get(int id, int l, int r, int b, int e) {
    if(l >= r) return 0;
    if(l >= e || r <= b) return 0;
    if(l >= b && r <= e) return sumg[id];
    push(id);
    int mid = l + (r - l) / 2;
    return get(id << 1, l, mid, b, e) + get(id << 1 | 1, mid, r, b, e);
  }

  void add(int l, int r) {
    add(1, 0, N, l, r);
  }

  int get(int l, int r) { return get(1, 0, N, l, r); }
} seg;

const int MaxN = 4e5 + 6.66;
int arr[MaxN];
int A[MaxN], B[MaxN], C[MaxN], D[MaxN];
int dis[MaxN];
map<int, int> cmp;

int compress(int t) {
  int I = 0;
  for(int i = 0; i < t; i++) cmp[C[i]] = cmp[A[i]] = 0;
  for(auto&x : cmp) x.second = I++;
  return I;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  long long ans = 0;

  map<int, vector<pair<int, int>>> lines;
  for(int i = 0; i < n; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    lines[B[i]].push_back({A[i], C[i]});
    lines[D[i]].push_back({A[i], C[i]});
  }
  int N = compress(n) - 1;
  int I = 0, prev = 0;
  for(auto x : cmp) {
    if(I == 0) {prev = x.first, I++; continue;}
    dis[I - 1] = abs(x.first - prev);
    prev = x.first;
    I++;
  }
  seg.build(N, &dis[0]);
  int pre = lines.begin()->first;
  for(auto x : lines) {
//    cout << pre << " " << x.first << " " << seg.get(0, N) << " " << ans<< endl;
    ans += 1ll * (x.first - pre) * seg.get(0, N);
//    cout << pre << " " << x.first << " " << seg.get(0, N) << " " << ans<< endl;
    for(auto y : x.second) {
      seg.add(cmp[y.first], cmp[y.second]);
    }
    pre = x.first;
  }
  cout << ans << endl;
  return 0;
}
