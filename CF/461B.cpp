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

const int MAXN = 1e5 + 100;
const int MOD = 1e9+7;
vi tree[MAXN];
bool c[MAXN];
ll dp[MAXN][2];

void dfs(int v,int prnt){
    if(c[v]){
        dp[v][0] = 1;
        dp[v][1] = 0;

        for(auto u : tree[v])
            if(u!=prnt){
                dfs(u,v);
                dp[v][0] = (dp[v][0] * ( dp[u][0] + dp[u][1] )) %MOD;
            }
                
    } else {
        ll prev = 1,nans;
        dp[v][0] = 0;
        dp[v][1] = 1;

        for(auto u : tree[v])
            if(u!=prnt){
                dfs(u,v);
                nans = (prev * dp[u][0] );
                dp[v][0] = (dp[v][0] * ( dp[u][0] + dp[u][1] )) %MOD;
                dp[v][1] = (dp[v][1] * ( dp[u][0] + dp[u][1] )) %MOD;
                prev     = (prev     * ( dp[u][0] + dp[u][1] )) %MOD;
                dp[v][0] = (dp[v][0] + nans) %MOD;
            }
        if(tree[v].size()<2 && prnt != -1)
            dp[v][0] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int x,n;
    cin >> n;
    FOR(i,1,n){
        cin >> x;
        tree[x].pb(i);
        tree[i].pb(x);
    }
    FOR(i,0,n)
        cin >> c[i];
    dfs(0,-1);
    cout << dp[0][0] %MOD << endl;
    return 0;
}
