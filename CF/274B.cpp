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

const int MAXN = 1e5+10;
ll dp[MAXN][2];
ll val[MAXN];
vector<int> tree[MAXN];

void dfs(int v,int prnt = -1){
    dp[v][0] = 0;
    dp[v][1] = 0;
    
    for(auto u : tree[v]){
        if(u==prnt) continue;
        dfs(u,v);
        FOR(i,0,2)dp[v][i] = max(dp[v][i], dp[u][i]);
    }
    ll nval = val[v] - dp[v][0] + dp[v][1];

    dp[v][nval<0] += abs(nval);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,x,y;
    cin >> n;
    FOR(i,1,n){
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    F0R(i,1,n)
        cin >> val[i];
    dfs(1);
    cout << dp[1][0] + dp[1][1] << endl;
    return 0;
}
