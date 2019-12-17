#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

int gcd(int x, int y) {
  return y == 0 ? gcd(y, x % y) : x;
}

int ans[10][10];
int m[15];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s; cin >> s;
  for(int x = 0; x < 10; x++, cout << "\n") {
    for(int y = 0; y < 10; y++) {
      memset(m, -1, sizeof m);

      for(int i = 0; i <= 10; i++)
        for(int j = 0; j <= 10; j++)
        {
          if(i == 0 && j == 0) continue;
          int c = (x * i + j * y) % 10;
          if(!~m[c]) m[c] = i + j;
          else m[c] = min(m[c], i + j);
        }
      int cnt = 0;
      bool ok = true;
      for(int i = 1; i < s.size(); i++) {
        int t = (10 + s[i] - s[i - 1]) % 10;
        if(~m[t]) {
          cnt += m[t] - 1;
        } else {
          ok = false;
          break;
        }
      }
      if(ok) ans[x][y] = cnt;
      else ans[x][y] = -1;
    }
  }
  return 0;
}
