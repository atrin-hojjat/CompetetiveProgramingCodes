#include <iostream>
#include <map>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n; 
    map<int, int> m;
    for(int i = 0; i < n; i++) {
      int a; cin >> a;
      while(a % 2 == 0) m[a]++, a /= 2;
    }
    cout << m.size() << endl;
  }
  return 0;
}
