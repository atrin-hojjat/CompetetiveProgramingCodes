#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string str;
  cin >> str;
  int n = str.size();
  long long cntv = 0, cntb = 0, cntw = 0;
  long long ans = 0;
  for(int i = n - 1; i > -1; i--) {
    if(str[i] == 'v') {
      cntv++;
      continue;
    } else {
      if(cntv) {
        ans += 1ll * cntb * (cntv - 1);
        cntw += cntv - 1;
        cntv = 0;
      }
      cntb += 1ll * cntw;
    }
  }
  if(cntv) {
    ans += 1ll * cntb * (cntv - 1);
    cntw += cntv - 1;
    cntv = 0;
  }
  cout << ans << endl;
  return 0;
}
