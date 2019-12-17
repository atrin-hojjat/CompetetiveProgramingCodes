#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
map<int, int> mp;
int arr[MaxN * 2];

int main() {
  int N; scanf("%d", &N);
  for(int i = 0; i < 2 * N; i++) scanf("%d", arr + i);
  for(int i = 0; i < 2 * N; i++) mp[arr[i]]++;
  sort(arr, arr + 2 * N);
  for(auto x : mp) 
    if(x.second >= N) {
      printf("0\n");
      return 0;
    }
  long long ans = 1ll * (arr[N - 1] - arr[0]) * (arr[2 * N - 1] - arr[N]);
  for(int i = 1; i <= N; i++)
    ans = min(ans, 1ll * (arr[2 * N - 1] - arr[0]) * (arr[i + N - 1] - arr[i]));
  printf("%lld\n", ans);
  return 0;
}
