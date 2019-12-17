#ifdef Atrin 
  #include <iostream>

#else
  #include <bits/stdc++.h>
#endif
#define int ll
using namespace std;
typedef long long ll;
const int mod = 1e9 + 9;
const int maxn = 1000;
const int maxk = 200;
int k,b;
int dp[maxk][maxn];
int vis[maxk][maxn];
int cnt[maxk][maxn];
int p2[maxk];
typedef pair<int,int> pii;
pii calc(int i,int m){
  if (i == b){
    if (m == 0) return {0,1};
    else return {0,0};
  }
  if (vis[i][m]) return {dp[i][m],cnt[i][m]};
  vis[i][m] = 1;
  pii p = calc(i + 1,m);
  dp[i][m] = p.first;
  cnt[i][m] = p.second;
  p = calc(i + 1,(m + p2[i]) % k);
  dp[i][m] += (p.first + p.second) % mod;
  dp[i][m] %= mod;
  cnt[i][m] += p.second;
  cnt[i][m] %= mod;
//cout << i << ' ' << m <<' ' << dp[i][m] <<  ' ' << cnt[i][m] << endl;
  return {dp[i][m],cnt[i][m]};
}
int32_t main(){
  cin >> k >> b;
  p2[0] = 1;
  for (int i = 1;i < maxk;i++)
    p2[i] = (p2[i - 1] * 2) % k;
  cout << calc(0,0).first << endl;
}
