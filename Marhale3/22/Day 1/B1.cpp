#include <bits/stdc++.h>
using namespace std;

const int delta = 46639;
char chtb[10][10];
int tab[10][10];
int cnt[50];

void input() {
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      cin >> tab[i][j];
}

int Pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * ans * base % delta;
  return ans;
}

int main() {
  input();
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      cnt[tab[i][j]] ++;
  int mn = -1, mx = -1;
  int mnv = 33, mxv = 0;
  for(int i = 1; i < 33; i++) {
    if(cnt[i] && cnt[i] < mnv) {
      mn = i;
      mnv = cnt[i];
    }
  }
  for(int j = 1; j < 33; j++)
    if(cnt[j] && cnt[j] > mxv) mx = j, mxv = cnt[j];
  cout << mn << " " << mx << endl;
  cout << (0ll + Pow(mn, 9) + Pow(mx, 9)) % delta << endl;
  return 0;
}
