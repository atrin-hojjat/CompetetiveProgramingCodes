#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1.5e5 + 6.66;
pair<int, int> nums[MaxN];
int n;

long long gcd(long long x, long long y) {
  return x == 0 ? y : gcd(y % x, x);
}

int get(int x) {
  for(int i = 1; i < n; i++)
    if(nums[i].first % x != 0 && nums[i].second % x != 0) return -1;
  return x;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x, y; scanf("%d %d", &x, &y);
    nums[i] = {x, y};
  }
  int ans = -1;
  for(int II = 0; II < 2; II++) {
    for(int i = 1; i <= sqrt(nums[0].first); i++) {
      if(nums[0].first % i) continue;
      if(i > 1) ans = get(i);
      if(~ans) break;
      ans = get(nums[0].first / i);
      if(~ans) break;
    }
    if(~ans) break;
    swap(nums[0].first, nums[0].second);
  }
  printf("%d\n", ans);
  return 0;
}
