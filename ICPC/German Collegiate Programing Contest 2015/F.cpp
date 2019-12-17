#include <iostream>
#include <time.h>
using namespace std;

long long mul(long long x, long long y, long long mod) {
  long long ret = 0;
  for(; y; y >>= 1, x = (x << 1) % mod)
    if(y & 1) ret = (ret + x) % mod;
  return ret;
}

long long _pow(long long base, long long exp, long long mod) {
  long long ret = 1;
  for(; exp; exp >>= 1, base = mul(base, base, mod))
    if(exp & 1) ret = mul(base, ret, mod);
  return ret;
}

bool check_prime(long long x, int iter = 1000) {
  srand(time(0));
  if(x < 4)
    return x == 2 || x == 3;
  while(iter--) {
    long long y = 2 + rand() % (x - 3);
    if(_pow(y, x - 1, x) != 1) return false;
  }
  return true;
}

int main() {
  long long num; cin >> num;
  if(num == 1) {
    cout << 1 << endl;
    return 0;
  }
  long long cnt = 1, W = num;
  for(long long i = 2; i <= 1e6 + 6.66; i++) {
    int c = 0;
    while(num % i == 0) c++, num /= i;
    cnt *= c + 1;
  }
  long long L = 2, R = 1e9 + 7;
  while(L < R) {
    long long mid = L + (R - L) / 2;
    if(mid * mid >= num) R = mid;
    else L = mid + 1;
  }
  if(L * L == num) cnt *= 3;
  else if(check_prime(num)) cnt *= 2;
  else if(num > 1) cnt *= 4;
  cout << cnt << endl;
  return 0;
}
