#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  while(T--) {
    int n, k; cin >> n >> k;
    if(k % 3) {
      if(n % 3) cout << "Alice" << endl;
      else cout << "Bob" << endl;
    } else {
      if(n < k) {
        if(n % 3) cout << "Alice" << endl;
        else cout << "Bob" << endl;
      } else if(n == k) cout << "Alice" << endl;
      else {
        int x  = n % (k + 1);
        if(x == k || x % 3) cout << "Alice" << endl;
        else cout << "Bob" << endl;
      }
    }
  }
  return 0;
}
