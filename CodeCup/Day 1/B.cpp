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
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 3e3+66.66;
const ll INF = 5e14+6.66;
ll a[MAXN];
ll dp[MAXN][MAXN][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,b;cin >> n >> b;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n)F0R(j,0,b) dp[i][j][0] = dp[i][j][1] = INF;
    dp[0][1][0] = 0;
    dp[0][0][1] = a[0];
    FOR(i,1,n) {
        F0R(j,0,b) {
            if(j>0)dp[i][j][0] = min(dp[i-1][j-1][0],a[i]+dp[i-1][j-1][1]);
            dp[i][j][1] = min(dp[i-1][j][1],dp[i-1][j][0]+a[i]);
        }
    }
    ll ans = 5e14 + 6.66;
    F0R(i,0,b) {
        if(n-i<=b) {
            ans = min({ans,dp[n-1][i][1],dp[n-1][i][0]});
        }
    }
    cout << ans << endl;
    return 0;
}
