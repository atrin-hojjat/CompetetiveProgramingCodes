#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21;
int adj[2][MAXN];
int w[2][MAXN];
bool dp[2][1<<MAXN];
vector<int> nums[2];
long long ans;

int count(int n,int I,int W) {
  int cnt = 0;
  dp[I][0] = true;
  for(int m = 1;m<(1<<n);m++) {
    int nei = 0;
    int wei = 0;
    for(int i = 0;i<n;i++)
      if((m>>i)&1) wei += w[I][i];
    bool ok = true;
    for(int i = 0;i<n;i++)
      if((m>>i)&1) ok &= dp[I][m ^ (1<<i)];
    for(int i = 0;i<n;i++)
      if((m>>i)&1) nei |= adj[I][i];
    if(ok && __builtin_popcount(nei) >= __builtin_popcount(m)) dp[I][m] = true;
    if(I && dp[I][m])
      ans += upper_bound(nums[I^1].begin(),nums[I^1].end(),W-wei,greater<int>()) - nums[I^1].begin() + (wei>=W);
    else if( I == 0 && dp[I][m]) nums[I].push_back(wei);
  }
  sort(nums[I].begin(),nums[I].end(),greater<int>());
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m;cin >> n >> m;
  for(int i = 0;i<n;i++) {
    string str;cin >> str;
    for(int j = 0;j<m;j++) {
      adj[0][i] |= (str[j] == '1')<<j;
      adj[1][j] |= (str[j] == '1')<<i;
    }
  }
  for(int i = 0;i<n;i++) cin >> w[0][i];
  for(int j = 0;j<m;j++) cin >> w[1][j];
  int WW;cin >> WW;
  count(n,0,WW) ,count(m,1,WW);
  cout << ans << endl;
  return 0;
}
