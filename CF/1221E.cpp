#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int Q; cin >> Q;
  while(Q--) {
    int a, b; cin >> a >> b;
    string str; cin >> str;
    int len = 0, x1 = 0, x2 = 0;
    for(auto x : str) {
      if(x == 'X') {
        if(len >= b && len < a) x1++;
        else if(len >= a && len <= a + 2 * b - 1) x2++;
        else if(len >= a + 2 * b) x1++;
      } else len++;
    }
    if(len >= b && len < a) x1++;
    else if(len >= a && len <= a + 2 * b - 1) x2++;
    else if(len >= a + 2 * b) x1++;
    if(x1 || x2 > 1) cout << "NO";
    else if(x2) cout << "YES";
    else cout << "NO";
    cout << endl;
  }
  return 0;
}
