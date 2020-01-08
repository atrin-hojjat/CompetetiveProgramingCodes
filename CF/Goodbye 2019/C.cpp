#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    long long sum = 0;
    long long xr = 0;
    for(int i = 0; i < n; i++) {
      int a; cin >> a;
      sum += a;
      xr = xr xor a;
    }
    cout << 2 << endl << xr << " " << xr + sum << endl;
  }
  return 0;
}
