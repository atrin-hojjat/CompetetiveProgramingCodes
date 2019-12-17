#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  while(T--) {
    pair<int, int> mn = {1000000, 100};
    for(int i = 0; i < 10; i++) {
      int x; cin >> x;
      mn = min(mn, {x + (i == 0), i});
    }
    if(mn.second == 0) {
      cout << 1;
      for(int i = 0; i < mn.first; i++) cout << mn.second;
    } else for(int i = 0; i < mn.first + 1; i++) cout << mn.second;
    cout << endl;
  }
  return 0;
}
