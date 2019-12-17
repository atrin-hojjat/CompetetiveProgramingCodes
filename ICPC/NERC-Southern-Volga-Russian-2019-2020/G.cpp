#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 2e5 + 6.66;
int a[MaxN], b[MaxN];

void Do(int& a, int& b) {
  int c = a;
  a = max(0, a - b);
  b = max(0, b - c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    vector<int> ans;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int A = 0, B = 0; bool ok = true;
    for(int i = 0; i < n; i++) {
      if(A + a[i] >= k) {
        Do(A, B);
        ans.push_back(i);
      }
      if(A + a[i] >= k) {
         ok = false;
         break;
      }
      A += a[i], B += b[i];
      if(B >= k) break;
    }
    if(ok && B >= k) {
      cout << ans.size() << endl;
      for(auto x : ans) 
        cout << x << " "; cout << endl;
    } else cout << -1 << endl;
  }
  return 0;
}
