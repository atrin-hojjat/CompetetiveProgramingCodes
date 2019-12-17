#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
bool w[MAXN];

int main() {
  int T;cin >> T;
  while(T--) {
    fill(w,w+MAXN,false);
    int a,b;cin >> a >> b;
    for(int i = 0;i<b;i++) {
      int x;cin >> x;
      w[x] = true;
    }
    int ZZ = b;
    for(int i = 0;i<5+a;i++) {
      bool ZZZZ = true;
      for(int i = 1;i<=a;i++)
        ZZZZ &= w[i];
      if(ZZZZ) {
        cout << i+1 << endl;
        break;
      }
      for(int j = 1;j<=a;j++) {
        if(!w[j] && w[j+1]) w[j] = true;
      }
      for(int j = a;j>0;j--)
        if(!w[j] && w[j-1]) w[j] = true;
    }
  }
  return 0;
}
