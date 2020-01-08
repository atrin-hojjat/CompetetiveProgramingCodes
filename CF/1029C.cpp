#include <iostream>
using namespace std;

const int MaxN = 3e5 + 6.66;
pair<int, int> segs[MaxN];
pair<int, int> parr[MaxN];
pair<int, int> parl[MaxN];

pair<int, int> get(pair<int, int> a, pair<int, int> b) {
  int l = max(a.first, b.first);
  int r = min(a.second, b.second);
  if(r - l >= 0) return {l, r};
  return {0, 0};
}

int size(pair<int, int> x) {
  return x.second - x.first;
}

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> segs[i].first >> segs[i].second;
  parl[0] = segs[0], parr[n - 1] = segs[n - 1];
  for(int i = 1; i < n; i++) parl[i] = get(parl[i - 1], segs[i]);
  for(int i = n - 2; i > -1; i--) parr[i] = get(parr[i + 1], segs[i]);
  pair<int, int> mx = parr[1];
  for(int i = 1; i <  n - 1; i++) if(size(get(parr[i + 1], parl[i - 1])) > size(mx)) mx = get(parr[i + 1], parl[i - 1]);
  if(size(parl[n - 2]) > size(mx)) mx = parl[n - 2];
  cout << size(mx) << endl;
  return 0;
}
