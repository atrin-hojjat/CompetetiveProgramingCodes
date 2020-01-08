#include <iostream>
using namespace std;

const int MaxN = 1e5 + 6.66;
int arr[MaxN];

int main() {
  int t; cin >> t;
  while(t--) {
    int n, s; cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    pair<int, int> mx = {0, 0};
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += arr[i];
      if(sum - max(arr[i], mx.first) > s) break;
      mx = max(mx, {arr[i], i + 1});
    }
    if(sum <= s) cout << 0 << endl;
    else cout << mx.second << endl;
  }
  return 0;
}
