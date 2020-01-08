#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

const int MaxN = 1e5 + 6.66;
int arr[MaxN];

int32_t main() {
  int N, M, v, p; cin >> N >> M >> v >> p;
  for(int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  int tot = p;
  long long sum = arr[N - p];
  int mx = arr[N - p];
  for(int i = N - p - 1; i > -1; --i) {
    if(mx > arr[i] + M) {
      break;
    }
    if(1ll * (arr[i] + M) * max(0ll, N - i - p) - sum >= 1ll * max(0ll, v - i - p) * M) tot++; 
    sum += arr[i];
  }
  cout << tot << endl;
  return 0;
}
