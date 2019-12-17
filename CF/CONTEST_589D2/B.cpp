#include <iostream>
using namespace std;

const int MaxN = 1e3 + 6.66;
int tab[MaxN][MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int h, w; cin >> h >> w;
  for(int i = 0; i < h; i++) {
    int x; cin >> x;
    for(int j = 0; j < x; j++)
      tab[i][j] = 1;
    tab[i][x] = -1;
  }
  for(int i = 0; i < w; i++) {
    int y;
    cin >> y;
    for(int j = 0; j < y; j++)
    {
      if(tab[j][i] == -1) {
        cout << 0 << endl;
        return 0;
      }
      tab[j][i] = 1;
    }
    if(tab[y][i] == 1) {
      cout << 0 << endl;
      return 0;
    }
    tab[y][i] = -1;
  }
  int cnt = 0;
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      if(tab[i][j] == 0) cnt++;
  int ans = 1;
  while(cnt--) {
    ans <<= 1;
    ans %= (int) 1e9 + 7;
  }
  cout << ans << endl;
  return 0;
}
