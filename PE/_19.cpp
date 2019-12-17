#include <bits/stdc++.h>
using namespace std;

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int ans = 0;
  int now = 365 % 7;
  for(int i = 1; i <= 100; i++) {
    for(int j = 0; j < 12; j++) {
      if(now == 6) ans++;
      now += months[j];
      if(j == 1 && (1900 + i) % 4 == 0 && ((1900 + i) % 100 != 0 || (1900 + i) % 400 == 0))
        now++;
      now %= 7;
    }
  }
  cout << ans << endl;
  return 0;
}
