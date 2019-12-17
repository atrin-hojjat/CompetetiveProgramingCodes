#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int x, y; cin >> x >> y;
    if(x >= 4) {
      cout << "yes" << endl;
      continue;
    }
    if(x == 1) {
      if(y == 1) cout << "yes" << endl;
      else cout << "no" << endl;
      continue;
    }
    if(y <= 3) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
