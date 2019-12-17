#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  long long n;cin >> n;
  int Q;cin >> Q;
  while(Q--) {
    long long s;cin >> s;
    long long x = ( s - 1 ) /2 + n - s;
    while(s%2 == 0 ) {
      long long w = s + x + 1;
      x = ( w - s - 1) /2;
      s = w;
    }
    cout << (s + 1) /2 << endl;
  }
  return 0;
}
