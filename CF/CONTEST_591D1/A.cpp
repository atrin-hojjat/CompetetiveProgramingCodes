#include <iostream>
#include <set>
using namespace std;

const int MaxN = 2e5 + 6.66;
int a[MaxN], b[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int Q; cin >> Q;
  while(Q--) {
    int n; cin >> n;
    int L = 0, R = n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int A, x1, B, x2; cin >> A >> x1 >> B >> x2;
    for(int i = 0; i < n; i++) b[i] = 0;
    for(int i = x1 - 1; i < n; i += x1) b[i] += A;
    for(int i = x2 - 1; i < n; i += x2) b[i] += B;
    b[n] = 10000000;
    sort(a, a + n);
    long long k; cin >> k;
    long long tot = 0;
    while(L < R) {
      int mid = L + (R - L) / 2;
      multiset<int> pers;
      for(int i = 0; i <= mid; i++) pers.insert(-b[i]);
      int I = n;
      tot = 0;
      for(auto x : pers) tot += 1ll * a[--I] / 100 * -x;
      if(tot >= k) {
        R = mid;
      } else L = mid + 1;
    }
    if(L == n) cout << -1 << endl;
    else cout << 1 + L << endl;
  }
  return 0;
}
