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
  int len = 0;
  int val = 1;
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++) {
      for(int xv = -1; xv < 2; xv++)
        for(int yv = -1; yv < 2; yv++) {
          if(xv == 0 && yv == 0) continue;
          int ls = 0;
          int l = 0;
          int x = i, y = j;
          int v = 1;
          while(x > -1 && y > -1 && x < 10 && y < 10) {
            if(ls > tab[x][y]) break;
            v = 1ll * v * tab[x][y] % delta;
            ls = tab[x][y];
            l++;
            x += xv, y += yv;
          }
          if(len < l) val = v, len = l;
        }
    }
  cout << len << " " << val << endl;
  cout << 1ll * val * val % delta << endl;
  return 0;
}
