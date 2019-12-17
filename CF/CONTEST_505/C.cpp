#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string str; cin >> str;
  int n = str.size();
  int ans = 0;
  char prv = '3';
  int len = 0;
  for(int i = 0; i < 2 * n; i++) {
    char now = str[i % n];
    if(now == prv) {
      ans = max(ans, len);
      len = 1;
    } else len++, prv = now;
  }
  ans = max(len, ans);
  cout << min(n, ans) << endl;
  return 0;
}
