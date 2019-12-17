#include <bits/stdc++.h>
using namespace std;

const int delta = 46639;
const int MaxN = 1 << 10;
vector<int> nums;
int dpor[MaxN];
int dpgcd[MaxN];
int dp[MaxN];
bool mark[MaxN];

void prep() {
  for(int i = 2; i < MaxN; i++)
    if(!mark[i]) {
      nums.push_back(i);
      for(int j = i * i; j < MaxN; j += i) mark[j] = true;
    }
}

int Pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * base * ans % delta;
  return ans;
}

int main() {
  prep();
  for(auto i : nums)
    for(auto j : nums)
      dpor[i | j] = 1;
  for(int i = 1; i < MaxN; i++)
    for(auto c : nums)
      if(dpor[i]) dpgcd[__gcd(i, c)] = 1;
  for(int i = 1; i < MaxN; i++)
    for(auto d : nums)
      if(dpgcd[i]) dp[i ^ d] = 1;
  int cnt = 0;
  int mn = MaxN;
  int mx = 0;
  for(int i = 0; i < MaxN; i++)
  {
    cnt += dp[i];
    if(dp[i]) {
      mn = min(mn, i);
      mx = i;
    }
  }
  cout << cnt << " " << mn << " " << mx << endl;
  cout << Pow(cnt, 9) << endl;
  cout << (Pow(mx, 2) + Pow(mn, 4)) % delta << endl;
  return 0;
}
