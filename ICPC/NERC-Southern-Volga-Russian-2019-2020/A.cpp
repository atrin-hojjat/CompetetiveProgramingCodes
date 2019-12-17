#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 4e5 + 6.66;
int last[MaxN], mx[MaxN], mn[MaxN];

int main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++)
    last[i + 1] = i, mx[1 + i] = mn[1 + i] = i + 1;
  vector<int> v;
  for(int i = 0; i < n; i++) v.push_back(i + 1);
  while(m--) {
    int a; cin >> a;
    if(last[a] != 0) {
      int b = v[last[a] - 1];
      mn[b] = min(mn[b], 1 + last[a]);
      mx[b] = max(mx[b], 1 + last[a]);
      mn[a] = min(mn[a], last[a]);
      mx[a] = max(mx[a], last[a]);
      swap(v[last[a]], v[last[a] - 1]);
      swap(last[a], last[b]);
    }
  }
  for(int a = 1; a <= n; a++)
  {
    int t = (last[a]);
    mx[a] = max(mx[a], 1 + t);
    mn[a] = min(mn[a], 1 + t);
  }
  for(int i = 1; i <=n; i++)
    cout << mn[i] << " " << mx[i] << endl;
  return 0;
}
