#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  long long x; cin >> x;
  long long g = x;
  for(long long i = 2; i * i <= x; i++) {
    if(x % i == 0) g = gcd(x / i, gcd(g, i));
  }
  cout << g << endl;
  return 0;
}
