#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 200 + 20 + 2;
bool arr[MAXN][MAXN];
bool pre[MAXN][MAXN];
bool suf[MAXN][MAXN];
bool tmp[MAXN];

int main() {
  int n,m; scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    for(int j = 0; j < m; j++) {
      char ch = str[j];
      arr[i][j] = (ch == '1');
    }
  }
  if(n == 1) {
    if(m) printf("NO\n");
    else printf("YES\n");
    return 0;
  }
  for(int i = 0; i < m; i++) pre[0][i] = arr[0][i];
  for(int i = 1; i < n; i++)
    for(int j = 0; j < m; j++)
      pre[i][j] = pre[i-1][j] || arr[i][j];
  for(int i = 0; i < m; i++) suf[n - 1][i] = arr[n - 1][i];
  for(int i = n-2; i > -1; i--)
    for(int j = 0; j < m; j++)
      suf[i][j] = suf[i + 1][j] || arr[i][j];
  for(int i = 0; i < n; i++) {
    memset(tmp, 0, sizeof tmp);
    if(i > 0)
      for(int j = 0; j < m; j++) tmp[j] = pre[i - 1][j];
    for(int j = 0; j < m; j++) tmp[j] = tmp[j] || suf[i + 1][j];
    bool ok = true;
    for(int j = 0; j < m; j++)
      ok &= tmp[j];
    if(ok) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
