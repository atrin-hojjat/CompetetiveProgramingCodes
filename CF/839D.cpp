#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int Max = 1e6 + 6.66;
const int mod = 1e9 + 7;
vector<int> revcounter[Max];
int pow2[Max];
int cnt[Max];
int ans[Max];

void prep() {
  pow2[0] = 1;
  for(int i = 1; i < Max; i++)
    pow2[i] = 2ll * pow2[i - 1] % mod;
}

int C2(int n) {
  return 1ll * n * (n - 1) / 2;
}

int main() {
  prep();
  int N; scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  for(int i = 2; i < Max; i++)
  {
    for(auto x : revcounter[i]) cnt[x] += cnt[i];
    for(int j = i + i; j < Max; j += i)
      revcounter[j].push_back(i);
  }
  int Ans = 0;
  for(int i = Max - 1; i > 1 ; i--) {
    ans[i] = 1ll * pow2[cnt[i] - 1] * cnt[i] % mod;
    for(int x = i + i; x < Max; x += i) 
    {
      ans[i] -= ans[x];
      if(ans[i] < 0) ans[i] += mod;
    }
    Ans = (Ans + 1ll * ans[i] * i % mod) % mod;
  }
  printf("%d\n", Ans);
  return 0;
}
