#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 6.66;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int base = 727;
int arr[MaxN];
struct Hash {
  int _1, _2;
  
  Hash() { _1 = _2 = 0; };
  Hash(long long c) {
    set(_1, mod1, c);
    set(_2, mod2, c);
  }

  void set(int&x, int mod, long long val) {
    if(val > 5ll * mod) val %= mod;
    while(val > mod) val -= mod;
    x = val;
  }

  bool operator==(Hash x) {
    return _1 == x._1 && _2 == x._2;
  }

  bool operator!=(Hash x) {
    return !(*this == x);
  }

  void fix(int&x, int mod) {
    if(x > 5ll * mod) x %= mod;
    else 
      while(x > mod) x -= mod;
  }

  Hash& operator+=(Hash w) {
    _1 += w._1;
    _2 += w._2;
    fix(_1, mod1);
    fix(_2, mod2);
    return *this;
  }

  Hash& operator+=(long long x) {
    Hash c(x);
    *this += c;
    return *this;
  }

  Hash& operator*=(Hash x) {
    set(_1, mod1, 1ll * x._1 * _1);
    set(_2, mod2, 1ll * x._2 * _2);
    return *this;
  }

  Hash& operator*=(long long x) {
    Hash c(x);
    *this *= c;
    return *this;
  }

  Hash operator+(Hash x) {
    Hash z = *this;
    return z += x;
  }

  Hash operator+(long long x) {
    Hash z = * this;
    return z += x;
  }

  Hash& operator-=(Hash x) {
    _1 -= x._1;
    _2 -= x._2;
    if(_1 < 0) _1 += mod1;
    if(_2 < 0) _2 += mod2;
    return *this;
  }

  Hash& operator-=(long long x) {
    Hash c = x;
    return *this -= c;
  }

  Hash operator-(Hash x) {
    Hash ret = *this;
    return ret -= x;
  }

  Hash operator-(long long x) {
    Hash c = x;
    return *this - c;
  }

  Hash operator*(Hash x) {
    Hash z = *this;
    return z *= x;
  }

  Hash operator*(long long x) {
    Hash z = *this;
    return z *= x;
  }
} pw[MaxN];

struct Bit {
  Hash bit[MaxN + 4];

  void add(int x, Hash val) {
    x += 2;
    while(x < MaxN) 
      bit[x] += val, x += x & -x;
  }

  Hash get(int x) {
    Hash ans = Hash();
    x += 1;
    while(x) ans += bit[x], x ^= x & -x;
    return ans;
  }

  Hash get(int l, int r) {
//    cout << l << " " << r << endl;
//    cout << (get(r) - get(l))._1 << endl;
    return get(r) - get(l);
  }
} self, rev;

void add(int n, int a) {
  self.add(a - 1, pw[a - 1]);
  rev.add(n - a, pw[n - a]);
}

bool check(int n, int x) {
  int cc = min(x - 1, n - x);
  if(x - 1 == n - x) 
    return self.get(x - 1 - cc, x - 1) != rev.get(n - x - cc, n - x);
  if(x - 1 > n - x)
    return self.get(x - 1 - cc, x - 1) != rev.get(n - x - cc, n - x) * pw[x - 1 - cc];
  return self.get(x - 1 - cc, x - 1) * pw[n - x - cc] != rev.get(n - x - cc, n - x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  if(n < 3) {
    cout << "NO" << endl;
    return 0;
  }
  pw[0] = 1;
  for(int i = 1; i < MaxN; i++) pw[i] = pw[i - 1] * base;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    add(n, arr[i]);
    if(check(n, arr[i])) {
//      cout << i << " " << arr[i] << endl;
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
