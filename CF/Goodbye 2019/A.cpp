#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n, a, b; cin >> n >> a >> b;
    bool win = false;
    for(int i = 0; i < n; i++)
    {
      int x; cin >> x;
      if(x == n) win = i < a;
    }
    if(win) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
