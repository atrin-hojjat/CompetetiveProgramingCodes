#include <bits/stdc++.h>
using namespace std;

const int delta = 46639;
char chtb[10][10];
int tab[10][10];

void input() {
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      cin >> tab[i][j];
}

int main() {
  input();
  int cnt = 0;
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      for(int x = -1; x < 10; x++)
        for(int y = -1; y < 10; y++)
        {
          if(x == 0 && y == 0) continue;
          x += i, y += j;
          if(x > -1 && y > -1 && x < 10 && y < 10 
              && tab[i][j] <= tab[x][y]) cnt++;
        }
  cout << cnt << endl;
  cout << 1ll * cnt * (delta - 999) % delta << endl;
  return 0;
}
