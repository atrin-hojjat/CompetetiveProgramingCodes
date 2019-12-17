#include <iostream>
using namespace std;

const int MaxN = 3e6 + 6.66;
string tab[666];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int r, c; cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> tab[i];
    int ans = 10;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++) if(tab[i][j] == 'A') ans = 4;
    for(int i = 0; i < r; i++)
      if(tab[i][0] == 'A' || tab[i][c - 1] == 'A') ans = 3;
    for(int j = 0; j < c; j++)
      if(tab[0][j] == 'A' || tab[r - 1][j] == 'A') ans = 3;
    for(int i = 0; i < r; i++) {
      int cnt = 0;
      for(int j = 0; j < c; j++)
        if(tab[i][j] == 'P') cnt = 1;
      if(!cnt) ans = 2;
    }
    for(int j = 0; j < c; j++)
    {
      int cnt = 0;
      for(int i = 0; i < r; i++)
        if(tab[i][j] == 'P') cnt = 1;
      if(!cnt) ans = 2;
    }
    if(tab[0][0] == 'A' || tab[r - 1][0] == 'A' || tab[r - 1][c - 1] == 'A' || tab[0][c - 1] == 'A') ans = 2;
    int cnt = 0;
    for(int i = 0; i < r; i++) if(tab[i][0] == 'P') { cnt++; break; }
    for(int i = 0; i < r; i++) if(tab[i][c - 1] == 'P') { cnt++; break; }
    for(int j = 0; j < c; j++) if(tab[0][j] == 'P') { cnt++; break; }
    for(int j = 0; j < c; j++) if(tab[r - 1][j] == 'P') { cnt++; break; }
    if(cnt < 4) ans = 1;
    cnt = 0;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        cnt += tab[i][j] == 'P';
    if(!cnt) ans = 0;
    if(ans > 4) cout << "MORTAL" << endl;
    else cout << ans << endl;
  }
  return 0;
}
