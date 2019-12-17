#include <iostream>
#include <cstring>
using namespace std;

const int Max = 19;
const int MaxN = (1 << Max) + 6.66;
long long dp[Max][MaxN];
long long mn[Max];
int arr[MaxN];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  bool saw = true;
  memset(mn, 63, sizeof mn);
  mn[0] = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] == -1) {
      saw = false;
      continue;
    }
    for(int j = __builtin_ctz(n); j > 0; j--) 
      if(i + 1 + saw >= (1 << j))
        mn[j] = min(mn[j], (saw ? 0 : arr[i]) + mn[j - 1]);
  }
  cout << mn[__builtin_ctz(n)] << endl;
  return 0;
}
