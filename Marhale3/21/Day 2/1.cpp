#include <bits/stdc++.h>
using namespace std;

const int delta = 10771;//1e6 + 3;
const int MaxN = 10;
int H[81];

int main() {
  pair<int, int> now = {0, 0};
  for(int i = 1; i < delta; i++) {
    pair<int, int> ne = now;
    switch(H[now.first * 9 + now.second] % 4) {
      case 2:
        ne.first--;
        if(ne.first < 0) ne.first += 9;
        break;
      case 3:
        ne.second++;
        if(ne.second >= 9) ne.second -= 9;
        break;
      case 0:
        ne.first++;
        if(ne.first >= 9) ne.first -= 9;
        break;
      case 1:
        ne.second--;
        if(ne.second < 0) ne.second += 9;
        break;
      default :
        break;
    }
    H[now.first * 9 + now.second]++;
    now = ne;
  }
  int ans = 1;
  for(int i = 0; i < 81; i++)
    ans = 1ll * ans * H[i] % delta;
  cout << ans << endl;
  return 0;
}
