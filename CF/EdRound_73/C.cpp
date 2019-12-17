#include <iostream>
#include <math.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int q; cin >> q;
  while(q--) {
    int a, b, c;
    cin >> a >> b >> c;
    int t = min(a, b);
    c += max(a, b) - t;
    if(t <= c) cout << t << endl;
    else cout << t - (t - c + 2) / 3 << endl;; 
  }
  return 0;
}
