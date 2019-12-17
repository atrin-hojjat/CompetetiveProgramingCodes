#include <iostream>
using namespace std;

const int MaxN = 2e5 + 6.66;
int arr[MaxN];

struct Segment {
  int seg[(int) (1e6 + 6.66)];
  int se[(int) (1e6 + 6.66)];

  void build(int id, int b, int e, int* arr) {
    if(b >= e) return ;
    if(b == e - 1) {
      seg[id] = arr[b];
      return;
    }
    int mid = b + (e - b) / 2;
    build(id << 1, b, mid, arr);
    build(id << 1 | 1, mid, e, arr);
  }

  void shift(int id, int nval) {
    se[id] = max(nval, se[id]);
  }

  void set(int id, int b, int e, int x, int val) {
    if(b >= e) return ;
    if(x >= e || x < b) return ;
    if(b == e - 1) {
      seg[id] = val;
      se[id] = 0;
      return ;
    }
    if(se[id]) {
      shift(id << 1, se[id]);
      shift(id << 1 | 1, se[id]);
      se[id] = 0;
    }
    int mid = b + (e - b) / 2;
    set(id << 1, b, mid, x, val);
    set(id << 1 | 1, mid, e, x, val);
  }

  void add(int id, int b, int e, int l, int r, int val) {
    if(b >= e) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      shift(id, val);
      return ;
    }
    if(se[id]) {
      shift(id << 1, se[id]);
      shift(id << 1 | 1, se[id]);
      se[id] = 0;
    }
    int mid = b + (e - b) / 2;
    add(id << 1, b, mid, l, r, val);
    add(id << 1 | 1, mid, e, l, r, val);
  }

  int get(int id, int b, int e, int x) {
    if(b >= e) return 0;
    if(x >= e || x < b) return 0;
    if(b + 1 == e) {
      return max(se[id], seg[id]);
    }
    if(se[id]) {
      shift(id << 1, se[id]);
      shift(id << 1 | 1, se[id]);
      se[id] = 0;
    }
    int mid = b + (e - b) / 2;
    return get(id << 1, b, mid, x) + get(id << 1 | 1, mid, e, x);
  }
} seg;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  seg.build(1, 0, n, &arr[0]);
  int m; cin >> m; 
  while(m--) {
    int t; cin >> t;
    if(t == 1) {
      int x, y; cin >> x >> y;
      seg.set(1, 0, n, x - 1, y);
    } else {
      int x; cin >> x;
      seg.add(1, 0, n, 0, n, x);
    }
  }
  for(int i = 0; i < n; i++) cout << seg.get(1, 0, n, i) << " "; cout << endl;
  return 0;
}
