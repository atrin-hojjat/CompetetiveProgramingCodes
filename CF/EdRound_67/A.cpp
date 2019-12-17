#include <iostream>
using namespace std;

int main() {
  int Q; cin >> Q;
  while(Q--) {
    int n, s, t; cin >> n >> s >> t;
    int w = t + s - n;
    cout << max(s, t) - w + 1 << endl;;
  }
  return 0;
}
