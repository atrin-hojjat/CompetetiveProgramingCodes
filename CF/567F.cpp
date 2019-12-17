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

const int MAXN = 40;
ll dp[MAXN*2][MAXN*2];
map<string,short> sign;
vector<pair<int,short>> rules[MAXN*2]; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,k;cin >> n >> k;
  sign["="] = 0;
  sign[">"] = 1;
  sign[">="] = 2;
  sign["<="] = 3;
  sign["<"] = 4;
  FOR(i,0,k) {
    int a,b;string ch;
    cin >> a >> ch >> b;
    rules[a].pb(mp(b,sign[ch]));
    rules[b].pb(mp(a,sign[ch]?5-sign[ch]:0));
  }
  dp[0][0] = 1;
  ll ans = 0;
  F0R(i,0,2*n) F0R(j,0,2*n) {
    if(i+j==2*n) ans+= dp[i][j];
//    if(i+j==2*n) cout << dp[i][j] << " " << i << " " << j << endl;
    if(i+j>=2*n) continue;
    if((i+j)%2) continue;
    int now = (i+j)/2;
    bool a1,a2,a3 ;a1 = a2 = a3 = true;
    int J = 2*n-j;
    for(auto x : rules[i+1]) {
      if(x.F>J) a2&= (x.S < 3 && x.S> 0),a1 &= (x.S < 3 && x.S> 0);
      if(x.F==J) a1&= !(x.S==4 || x.S == 1);
      if(x.F<=i) a2&= (x.S < 3 && x.S> 0),a1 &= (x.S < 3 && x.S> 0);
    }
    for(auto x : rules[J]) {
      if(x.F>J) a3&= (x.S < 3 && x.S> 0),a1 &= (x.S < 3 && x.S> 0);
      if(x.F==i+1) a1&= !(x.S==4 || x.S == 1);
      if(x.F<=i) a3&= (x.S < 3 && x.S> 0),a1 &= (x.S < 3 && x.S> 0);
    }
    for(auto x : rules[i+2]) {
      if(x.F>J) a2&= (x.S < 3 && x.S> 0);
      if(x.F==i+1) a2&= !(x.S==4 || x.S == 1);
      if(x.F<=i) a2&= (x.S < 3 && x.S> 0);
    }
    for(auto x : rules[J-1]) {
      if(x.F>J) a3&= (x.S < 3 && x.S> 0);
      if(x.F==J) a3&= !(x.S==4 || x.S == 1);
      if(x.F<=i) a3&= (x.S < 3 && x.S> 0);
    }
//    cout << i << " " << j << " " << a1 << " " << a2 << " " << a3 << " " << dp[i][j] << endl;
    if(a1) dp[i+1][j+1] += dp[i][j];
    if(2*n-i-j > 2 && a2) dp[i+2][j] += dp[i][j];
    if(2*n-i-j > 2 && a3) dp[i][j+2] += dp[i][j];
  }
  cout << ans << endl;
	return 0;
}
