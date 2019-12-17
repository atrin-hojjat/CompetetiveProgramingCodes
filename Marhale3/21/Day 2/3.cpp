#include <bits/stdc++.h>
using namespace std;

const int delta = 10771;//1e6 + 3;
bool mark[1391];

int main() {
  int ans = 1;
  for(int i = 1; i < 1391; i++) {
    if(mark[i]) continue;
    int now = i;
    int cnt = 0;
    while(now < 1391) {
      mark[now] = true;
      cnt++;
      now <<= 1;
    }
    ans = 1ll * ans * cnt % delta;
  }
  cout << ans << endl;
  return 0;
}
