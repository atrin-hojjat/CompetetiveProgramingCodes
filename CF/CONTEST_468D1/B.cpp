#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 6.66;
int cnt[26][26][5000];
int C[26];

int main() {
  string str;cin >> str;
  int n = str.size();
  for(int i = 0;i<n;i++) {
    C[str[i] - 'a']++;
    for(int j = 0;j<n;j++) {
      if(i == j) continue;
      cnt[str[i] - 'a'][str[j] - 'a'][(n + j - i ) %n]++;
    }
  }
  long double ans = 0;
  int ww = 0;
  for(int i = 0;i<26;i++) {
    if(!C[i]) continue;
    long double mx = 0;
    for(int l = 1;l<n;l++) {
      int win = 0;
      int tot = 0;
      for(int j = 0;j<26;j++) win += (cnt[i][j][l] == 1),tot += cnt[i][j][l];
      mx = max(mx, 1.0l * win / tot) ;
    }
    ans += mx * C[i];
    ww ++;
  }
  ans /= n;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
