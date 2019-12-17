#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
  int ans = 6e5 + 6.66;
  ans = min(ans, abs(b - a) + abs(b - c) + abs(c - d) + abs(d - e));
  ans = min(ans, abs(b - a) + abs(b - d) + abs(d - c) + abs(c - e));
  ans = min(ans, abs(b - a) + abs(b - d) + abs(d - e) + abs(c - e));
  swap(d, b), swap(e, c);
  ans = min(ans, abs(b - a) + abs(b - c) + abs(c - d) + abs(d - e));
  ans = min(ans, abs(b - a) + abs(b - d) + abs(d - c) + abs(c - e));
  ans = min(ans, abs(b - a) + abs(b - d) + abs(d - e) + abs(c - e));
  cout << ans << endl;
  return 0;
}
