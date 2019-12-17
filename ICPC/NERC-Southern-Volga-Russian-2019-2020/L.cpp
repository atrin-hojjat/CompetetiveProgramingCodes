#include <iostream>
using namespace std;

int get_min(int a, int b, int c) {
  int ans = max(max(a, b), c);
  for(int i = 0; i <= b; i++) 
    for(int j = 0; j <= a; j++) {
      if(a - j < j) break;
      // a - j / j / c + i
      // b - i - x / x / 0
      int cc = b - i - (a - 2 * j);
      if(cc >= 0) ans = min(ans, max(max(a - j + cc / 2, a - j + (cc + 1) / 2), c + i));
      else ans = min(ans, max(max(a - j, j + b - i), c + i));
    }
  return ans;
}

int main() {
  int T; cin >> T;
  while(T--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(get_min(a, b, c), get_min(c, b, a)) << endl;
  }
  return 0;
}
