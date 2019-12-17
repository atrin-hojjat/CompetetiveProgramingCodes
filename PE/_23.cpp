#include <bits/stdc++.h>
using namespace std;

const int MaxN = 28123 + 6.66;
int sum[MaxN];

int main() {
  for(int i = 1; i < MaxN; i++)
    for(int j = i + i; j < MaxN; j += i) sum[j] += i;
  vector<int> ab;
  for(int i = 2; i < MaxN; i++)
    if(sum[i] > i) ab.push_back(i);
  long long ans = 0;
  for(int i = 1; i < MaxN; i++) {
    int l = 0, r = ab.size() - 1;
    while(l < r) {
      int s = ab[l] + ab[r];
      if(s == i) break;
      if(s < i) l++;
      if(s > i) r--;
    }
    if(ab[l] + ab[r] != i) ans += i;
  }
  cout << ans << endl;
  return 0;
}
