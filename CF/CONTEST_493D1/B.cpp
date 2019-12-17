#include <bits/stdc++.h>
using namespace std;

map<int, int> ma;
int a[4] = {1, 5, 10, 50};
int ans[50];

void backtrack(int m, int on, int p = 0) {
  if(m == 0) {
    ma[p]++;
    return ;
  }
  backtrack(m - 1, on, p + a[on]);
  for(int i = on + 1; i < 4; i++)backtrack(m - 1, i, p + a[i]);
}

int main() {
  int n; cin >> n;
  if(n < 51) {
    backtrack(n, 0, 0);
    cout << ma.size() << endl;
  } else {
    memset(ans, 63, sizeof ans);
    int xx = 0;
    for(int i = 0; i < 50; i++)
      for(int j = 0; j < 50; j++) 
      {
        xx = (i * 4 % 49 + j * 9 % 49) % 49;
        ans[xx] = min(i + j, ans[xx]);
      }
    ans[0] = 1;
    long long Ans = 0;
    for(int i = 0; i < 49; i++) {
      if(n >= ans[i]) Ans += 1ll * (n - ans[i] + 1);
    }
    cout << Ans + 1 << endl;
  }
  return 0;
}
