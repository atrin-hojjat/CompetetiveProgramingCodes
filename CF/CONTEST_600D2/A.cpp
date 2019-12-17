#include <iostream>
using namespace std;

const int MaxN = 1e5 + 6.66;
int a[MaxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    bool ok = true;
    int p = 0;
    for(int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      a[i] -= x;
      if(a[i] != 0) {
        if(a[i] > 0) ok = false;
        else if(p == 0) p = a[i];
        else {
          if(a[i - 1] != a[i]) {ok = false; }
        }
      }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
