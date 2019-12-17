#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 6.66;
int n, x, y;
string str;

long long solve(char w) {
  int sz = 0, cnt = 0, cntc = 0;
  for(auto x : str) {
    if(x == w) {
      if(sz) cntc++;
      sz = 0;
    } else sz += 1, cnt++;
  }
  if(sz) cntc++;
  if(cntc == 0) return 0;
  return min(1ll * cntc * y, 1ll * (cntc - 1) * x + y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> x >> y;
  cin >> str;
  cout << min(solve('1'), solve('0') + y) << endl;
  return 0;
}
