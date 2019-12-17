#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  int mn = 1 + n;
  for(int i = 1; i <= n; i++) {
    int j = n / i;
    if(i * j == n) mn = min(mn, i + j);
  }
  cout << 2 * mn << endl;
  return 0;
}
