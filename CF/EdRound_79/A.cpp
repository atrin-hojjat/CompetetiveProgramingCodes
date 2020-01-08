#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    long long a, b, c; cin >> a >> b >> c;
    if(max(a, max(b, c)) > a + b + c - max(max(a, b), c) + 1) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
  return 0;
}
