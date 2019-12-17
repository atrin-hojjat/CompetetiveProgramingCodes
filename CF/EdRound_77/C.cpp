#include <iostream>
using namespace std;

int gcd(int a, int b) {
  return a == 0 ? b : gcd(b % a, a);
}

int main() {
  int T; cin >> T;
  while(T--) {
    int r, b, k; cin >> r >> b >> k;
    int t = gcd(r, b);
    if(r > b) swap(r, b);
    int z = (b + r - t - 1) / r;
    if(z >= k) cout << "REBEL" << endl;
    else cout << "OBEY" << endl;
  }
  return 0;
}
