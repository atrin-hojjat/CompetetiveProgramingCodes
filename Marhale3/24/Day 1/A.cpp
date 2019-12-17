#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int delta = 10313;
const int mod = delta;
int p2[MaxN];

void prep() {
  p2[0] = 1;
  for(int i = 1; i < MaxN; i++) p2[i] = 2ll * p2[i - 1] % delta;
}

int sum(int x) {
  return 1ll * x * (x - 1) / 2 % delta;
}

int& add(int&x, long long y) {
  y %= delta;
  x += y;
  if(x >= delta) x -= delta;
  return x;
}

int Max(int N) {
  int s = sum(p2[N]);
  int s2 = 0;
  for(int i = N - 1; i > -1; i--) {
    add(s2, p2[i]);
    add(s, 1ll * sum(p2[i]) + 1ll * p2[i] * s2 % delta);
  }
  cout << "max : " << s << endl;
  return s;
}

int Min(int N) {
  int s = sum(p2[N]);
  for(int i = N - 1; i > -1; i--) {
    add(s, 1ll * p2[N - i] * sum(p2[i]) % mod + 1ll * p2[N - i] * p2[i] % delta - p2[i] + mod);
  }
  cout << "min : " << s << endl;
  return s;
}

int main() {
  int N; cin >> N;
  prep();
  int x = 1ll * Min(N) * Max(N) % delta;
  x = 1ll * x * x % delta;
  cout << x << endl;
  return 0;
}
