#include <iostream>
using namespace std;

const int MaxN = 500;
int cnt[MaxN];

int main() {
  int q;
  cin >> q;
  while(q--) {
    int n; cin >> n;
    for(int i = 0; i < MaxN; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      cnt[__builtin_ctz(x)]++;
    }
    for(int i = 0; i < 30; i++) cnt[i + 1] += cnt[i] / 2;
    if(cnt[11]) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
