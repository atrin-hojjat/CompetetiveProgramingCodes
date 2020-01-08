#include <iostream>
using namespace std;

int main() {
  long long a, b, n; cin >>  n >> a >> b;
  if((a - b) % 2 == 0) {
    cout << abs(a - b) / 2 << endl;
    return 0;
  }
  cout << min(min(a, b) + abs(a - b) / 2, n - max(a, b) + abs(a - b) / 2 + 1) << endl;
  return 0;
}
