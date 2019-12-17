#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  while(T--) {
    int n, x, a, b; cin >> n >> x >> a >> b;
    int dis = a - b;
    if(dis < 0) dis *= -1;
    dis = min(dis + x, n - 1);
    cout << dis << endl;
  }
  return 0;
}
