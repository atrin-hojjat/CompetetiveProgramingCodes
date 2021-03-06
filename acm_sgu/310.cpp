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
#define ITFOR(it,v)         for(v::iterator it =v.begin();it!=v.end();++it)
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

ll dp[2][1<<17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    ll ans = 0;
    bool x = false;
    FOR(mask,0,1<<m)
        if(__builtin_popcount(mask)<k)
            dp[x][mask] = 0;
        else 
            dp[x][mask] = 1;
    FOR(i,m,n){
        fill(dp[!x],dp[!x]+(1<<m),0);
        FOR(mask1,0,1<<m){
            if(__builtin_popcount(mask1) < k) {continue;}
            int mask = ((1<<m)-1)&(mask1<<1);
            int c = __builtin_popcount(mask);
            dp[!x][mask|1] += dp[x][mask1];
            if(c>k-1)
                dp[!x][mask] += dp[x][mask1];
        }
        x = !x;
    }
    FOR(i,0,1<<m)
        ans += dp[x][i];
    cout << ans << endl;
    return 0;
}
