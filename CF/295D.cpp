#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>

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
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 2e3+6.66;
const int MAXM = 2e3+6.66;
const ll  MOD  = 1e9+7;
ll dp[MAXN][MAXM];
ll dp1[MAXN][MAXM];
ll par[MAXN][MAXM];
ll par2[MAXN][MAXM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(sz,0,m-1)
        dp[0][sz] = 1;
    F0R(i,1,n) {
        FOR(j,0,m-1) {
            if(i==1) {
                dp[i][j] = 1;
                dp1[i][j] = 1;
                par[i][j] = j+1;
                par2[i][j] = par2[i][j-1] + j+1;
                continue;
            }
            dp1[i][j] = (1+((2+j)*par[i-1][j-1])%MOD*1LL-par2[i-1][j-1]*1LL+MOD)%MOD;
            dp[i][j] = (1+((2+j)*par[i-1][j])%MOD-par2[i-1][j] + MOD)%MOD;
            par[i][j] = (par[i][j-1] + dp[i][j])%MOD;
            par2[i][j] = (par2[i][j-1] + (1LL * (j+1LL)*dp[i][j])%MOD)%MOD;
        }
    }
    ll ans = 0LL;
    FOR(t,0,n) FOR(sz,0,m-1) {
        ans = (ans + (((m-sz-1LL) * 1LL * dp[t+1][sz])%MOD * dp1[n-t][sz])%MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}
