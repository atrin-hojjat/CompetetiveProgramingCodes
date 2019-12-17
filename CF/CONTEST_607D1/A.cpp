#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) {
    int x; cin >> x;
    string str; cin >> str;
    char *a = new char[max(x + 3, (int) str.size())], *b = a, *c = a;
    for(auto x : str) *b++ = x;
    long long sz = str.size();
    for(int i = 0; i < x; i++) {
      int s = *c++ - '0';
      char *d = c, *start = c, *fin = b;
      sz = sz + 1ll * (s - 1) * (0ll + sz - (c - a) + mod);
      while(sz >= mod) sz -= mod;
      while(--s) {
        d = start;
        while(d != fin && b - a < x) {
          *b++ = *d++;
        }
      }
    }
    cout << sz << endl;
  }
  return 0;
}
