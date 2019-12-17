#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>

#define mp                  make_pair
#define F                   first
#define S                   second
#define pb                  push_back
#define FOR(i,j,n)          for(int i=j;i<n;i++)
#define F0R(i,j,n)          for(int i=j;i<=n;i++)
#define RFOR(i,j,n)         for(int i=n-1;i>=j;i--)
#define RF0R(i,j,n)         for(int i=n;i>=j;i--)
#define FOREACH(x,v)        for(auto x:v)
#define ITFOR(it,v)         for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " <<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 500+6.66;
int dp[2][MAXN][MAXN];
int st[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m,MOD;cin >> n >> m >> MOD;
  for(int i = 0;i<m;i++) {
    string str;cin >> str;
      for(int j = 0;j<n;j++)
        st[j] += str[j]=='1';
  }
  int CNT = 0,CNN = 0;
  for(int i = 0;i<n;i++)
    if(st[i] == 0) CNT++;
    else if (st[i] == 1) CNN++;
  dp[0][CNN][CNT] = 1;
  bool nn = 0;
  int CXX = max(CNN-2,0),CXT = max(CNT-2,0);
  CNN = CNT+CNN;
  int W = min((n-m+1)*2,n);
  for(int I = m;I<n;I++,nn^=1) {
//    cout << CXX << " "<< CNN << " " << CXT << " " << CNT << endl;
    for(int i = (CXX|1)^1;i<=CNN;i+=2)
      for(int j = CXT;j<=CNT;j++) {
        dp[1^nn][i][j] = (1LL*(i+2)*(i+1)*dp[nn][i+2][j]/2 + 1LL*i*(1+j) * dp[nn][i][j+1]
            + (i>1 ? 1LL*(j+2)*(j+1)*dp[nn][i-2][j+2]/2 : 0LL ))%MOD;
//        cout << "\t" << dp[!nn][i][j] << " " << i << " " << j << endl;
      }
    CXT = max(CXT-2,0);
    CXX = max(CXX-2,0);
//    CNN = min(CNN+2,n);
  }
  cout << dp[nn][0][0] << endl;
	return 0;
}
