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

int Pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * base * ans % delta;
  return ans;
}

int main() {
  input();
  set<int> words;
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      for(int x = -1; x < 2; x++)
        for(int y = -1; y < 2; y++) {
          if(x == 0 && y == 0) continue;
          x += i, y += j;
          if(x > -1 && y > -1 && x < 10 && y < 10 
              && tab[i][j] <= tab[x][y])
            words.insert(tab[i][j] + 33 * tab[x][y]);
        }
  cout << words.size() << endl;
  int ans = Pow(words.size(), 7);
  int j = 1ll * words.size() * (delta - 777) % delta;
  cout << (ans + j) % delta << endl;
  return 0;
}
