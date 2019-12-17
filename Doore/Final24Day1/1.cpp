#include <bits/stdc++.h>
using namespace std;

const int MaxN = 400 + 40 + 4;
const int mod = 1e9 + 7;
int D[16][16 * 400 + 30];
int dp[16][1 << 16];
int DD[MaxN * MaxN];
int ss[1 << 15];
int arr[MaxN];

void calc_knap(int n) {
  DD[0] = 1;
  for(int i = 0; i < n; i++)
    for(int j = MaxN * MaxN - 1; j >= arr[i]; j--)
    {
      DD[j] += DD[j - arr[i]];
      if(DD[j] >= mod) DD[j] -= mod;
    }
  for(int i = 2; i < MaxN * MaxN; i++)
  {
    DD[i] += DD[i - 1];
    if(DD[i] >= mod) DD[i] -= mod;
  }
}

void backtrack(int n) {
  for(int i = 1; i < (1 << n); i++)
  {
    int s = 0;
    for(int j = 0; j < n; j++)
      if(i & (1 << j)) s += arr[j];
    ss[i] = s;
    dp[1][i] = s;
    D[1][s]++;
  }
  for(int k = 2; k <= n; k++)
    for(int i = 1; i < (1 << n); i++)
    {
      dp[k][i] = dp[k - 1][i];
      for(int mask = i; mask; mask = (mask - 1) & i)
        dp[k][i] = min(dp[k][i], max(dp[1][mask], dp[k - 1][i ^ mask]));
      D[k][dp[k][i]]++;
      if(D[k][dp[k][i]] >= mod) 
        D[k][dp[k][i]]-= mod;
    }
  for(int k = 1; k <= n; k++)
    for(int d = 2; d < 16 * 400 + 10; d++)
      (D[k][d] += D[k][d - 1]) %= mod;
}

int main() {
  int n, Q; cin >> n >> Q;
  for(int i = 0; i < n; i++) cin >> arr[i];
  calc_knap(n);
  if(n <= 16) backtrack(n);
  while(Q--) {
    int k, d; cin >> k >> d;
    if(k == 1) cout << DD[d] << endl;
    else if(n <= 16) 
      cout << D[min(n, k)][min(16 * 400 + 1, d)] << endl;
  }
  return 0;
}
