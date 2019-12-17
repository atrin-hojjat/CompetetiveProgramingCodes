#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
const int mod = 10369;
const int delta = mod;
int a[] = {972,  -1, 273, -1, 932, 911,  -1, 233};
int b[] = { -1, 942, 135, -1, 371,  -1, 311,  -1};
int dp[2][MaxN];
int tmp[MaxN];

int _pow(int base, int exp, int m = mod) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % m)
    if(exp & 1) ans = 1ll * base * ans % m;
  return ans;
}

pair<int, int> get(int x[], int i) {
  if(x[i] == -1) return {100, 1000};
  else return {x[i], 1 + x[i]};
}

int& add(int &x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int main() {
  int k; cin >> k;
  bool now = true;
  dp[0][777] = 1;
  for(int i = 0; i < k; i++) {
    for(int i = 0; i < 1000; i++) dp[now][i] = 0;
    pair<int, int> x1 = get(a, i);
    pair<int, int> x2 = get(b, i);
    for(int B = x2.first; B < x2.second; B++) {
      memset(tmp, 0, sizeof tmp);
      for(int A = x1.first; A < x1.second; A++)
        for(int x = 0; x < 1000; x++)
          add(tmp[x * A % B], dp[not now][x]);
      for(int j = 0; j < B; j++)
        add(dp[now][(i + 1 + j) % B], tmp[j]);
    }
    now = not now;
  }
  int ans = dp[not now][777];
  for(int i = k; i < 8; i++)
  {
    if(a[i] == -1) ans = 1ll * ans * 900 % delta;
    if(b[i] == -1) ans = 1ll * ans * 900 % delta;
  }
  cout << ans << endl;

  return 0;
}
