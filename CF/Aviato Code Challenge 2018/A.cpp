#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 5;
string str;
bool pal[MAXN][MAXN];

int main() {
  cin >> str;
  int n = str.size();
  for(int i = 0; i < n; i++) {
    pal[i][i] = true;
    if(i < n - 1)pal[i][i+1] = str[i] == str[i + 1];
  }

  for(int i = n - 1; i > -1; i--)
    for(int j = i + 2; j < n; j++)
      pal[i][j] = pal[i+1][j-1] && (str[i] == str[j]);
  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++)
      if(!pal[i][j]) ans = max(ans, j - i + 1);
  cout << ans << endl;
  return 0;
}
