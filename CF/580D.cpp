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
#define ITFOR(it,v)         for(decltype(v)::iterator it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

ll dp[1<<18][20];
ll a[20];
ll con[20][20];
ll n,m,k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll x,y,c;
    cin >> n >> m >> k;
    FOR(i,0,n)cin >> a[i];
    FOR(i,0,k){
        cin >> x >> y >> c;
        y--,x--;
        con[x][y] = c;
    }
    ll ans = 0;
    FOR(i,0,n)dp[1<<i][i] = a[i];
    FOR(i,0,1<<n)
        FOR(j,0,n){
            if(((1<<j)&i)==0)continue;
            if(__builtin_popcount(i)==m){ans = max(ans,dp[i][j]);continue;}
            FOR(k,0,n)
                if(((1<<k)&i)==0)
                    dp[i|(1<<k)][k] = max(dp[i|(1<<k)][k],dp[i][j] + con[j][k] + a[k]);
        }

    cout << ans << endl;
    return 0;
}
