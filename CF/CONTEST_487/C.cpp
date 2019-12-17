#include <bits/stdc++.h>
using namespace std;

const int MaxN = 50 + 6.66;
int tab[MaxN][MaxN];
int ll;

void fillAs() {
  for(int kk = 0; kk < 16; kk++) {
    for(int i = 0; i < 50; i++)
      tab[kk << 1][i] = 1;
    for(int i = 1; i < 50; i += 2)
      tab[kk << 1 | 1][i] = 1;
    ll += 2;
  }
}

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  a--;
  fillAs();
  d--;
  int st1 = 0, st2 = 0;
  while(b || c || d) {
    int ow = (b > 0 ? 2 : c > 0 ? 3 : 4);
    for(; st1 < 40; st1++)
    {
      bool ok = false;
      for(; st2 < 50; st2++) {
        if(!tab[st1][st2]) {
          tab[st1][st2] = ow;
          if(b) b--;
          else if(c) c--;
          else if(d) d--;
          ok = true;
          break;
        }
      }
      if(ok) break;
      st2 = 0;
    }
  }
  tab[ll - 1][0] = 4;
  if(a) {
    for(int i = 0; i < 50; i++)
      tab[ll][i] = 4;
    ll++;
  }
  for(int i = 0; i < 5; i++) {
    for(int i = 0; i < 50 && a; i+= 2)
      tab[ll][i] = 1, a--;
    for(int i = 0; i < 50; i++)
      if(!tab[ll][i]) tab[ll][i] = 4;
    ll++;
    for(int i = 0; i < 50; i++)
      tab[ll][i] = 4;
    ll++;
    if(!a) break;
  }
  cout << ll << " " << 50 << endl;
  for(int i = 0; i < ll; i++) {
    for(int j = 0; j < 50; j++) {
      if(!tab[i][j]) tab[i][j] = 1;
      char ch = 'A' + tab[i][j] - 1;
      cout << ch;
    }
    cout << endl;
  }
  return 0;
}
