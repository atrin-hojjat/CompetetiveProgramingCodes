#include <iostream>
using namespace std;

int main() {
  int Q; cin >> Q;
  while(Q--) {
    int a, b; cin >> a >> b;
    if(b < a) swap(a, b);
    if(b > 2 * a) cout << "NO";
    else if((a + b) % 3 ) cout << "NO";
    else cout << "YES";
    cout << endl;
  }
  return 0;
}
