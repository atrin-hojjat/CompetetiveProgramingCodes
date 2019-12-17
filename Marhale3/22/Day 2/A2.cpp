#include <bits/stdc++.h>
using namespace std;

const int delta = 10369;
const int MaxN = delta; //12'299'390;
int cnt[MaxN];
int ps[MaxN];
long long ans[MaxN];

void prep() {
  for(int i = 1; i < MaxN; i++)
    for(int j = i; j < MaxN; j += i) cnt[j]++;

  for(int i = MaxN - 1; i > 0; i--)
  {
    int kk = (MaxN - 1) / i;
    ans[i] = 1ll * kk * kk;
    for(int j = i + i; j < MaxN; j += i)
      ans[i] -= ans[j];
  }
}

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * ans * base % delta;
  return ans;
}

int main() {
  prep();
  long long xx = 0;
  for(int i = 1; i < MaxN; i++)
    if(cnt[i] == 48) xx += ans[i];
  cout << _pow(xx % delta, xx % (delta - 1)) << endl;
  return 0;
}
