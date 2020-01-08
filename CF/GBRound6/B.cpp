#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  while(T--) {
    long long x; cin >> x;
    if(x > 14 && x % 14 > 0 && x % 14 < 7) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
