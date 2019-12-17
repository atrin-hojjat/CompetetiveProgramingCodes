#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e6 + 6.66;
const int mod = 1e9 + 7;
vector<int> divs[MaxN];
bool mark[MaxN];
int cnt[MaxN];
int cc[MaxN];
int pown[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

void prep() {
  fill(mark, mark + MaxN, true);
  for(int i = 2; i < MaxN; i++) {
    if(cnt[i]) continue;
    for(int j = i; j < MaxN; j += i)
    {
      cnt[j]++;
      if(mark[j] && i < 2e3 + 6.66 && 1ll * j % (i * i) == 0ll) mark[j] = false;
    }
  }
  for(int i = 2; i < MaxN; i++)
    if(mark[i])
      for(int j = i; j < MaxN; j += i) divs[j].push_back(i);
}

int main() {
  prep();
  int n, K; scanf("%d %d", &n, &K);
  int Ans = 0, prev = 0;
  for(int i = 1; i < MaxN; i++) pown[i] = _pow(i, n);
  for(int k = 1; k <= K; k++) {
    int ans = pown[k] - pown[k - 1] + mod;
    ans = ans % mod;
    ans = (ans + prev) % mod;
    for(auto x : divs[k]) 
    {
      cc[x]++;
      int w = pown[cc[x]] - pown[cc[x] - 1] + mod;
      w %= mod;
      ans = (0ll + ans + (cnt[x] % 2 ? -1 : 1) * w + mod) % mod;
    }
    prev = ans;
    Ans = (Ans + (k ^ ans)) % mod;
  }
  printf("%d\n", Ans);
  return 0;
}
