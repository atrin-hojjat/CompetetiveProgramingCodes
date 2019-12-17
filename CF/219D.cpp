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
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)              cout << "[ !" << __LINE__ << "L ] " \
    << x << endl;

using   namespace std;

typedef long long       ll;
typedef pair<ll,ll>     pll;
typedef pair<int,int>   pii;
typedef vector<int>     vi;
typedef vector<pii>     vii;
typedef vector<ll>      vl;

const int MAXN = 2e5 + 100;
int dp[MAXN];
vi tree[MAXN][2];

void dfs0(int v,int prnt){
    dp[v] = 0;
    
    FOR(i,0,2)
        for(auto u : tree[v][i]) {
            if(u==prnt)continue;
            dfs0(u,v);
            dp[v] += dp[u] + i;
        }
}

void dfs1(int v,int prnt,int val){
    dp[v] += val;
    FOR(i,0,2)
        for(auto u : tree[v][i])
            if(u!=prnt)
                dfs1(u,v,dp[v] - dp[u] + (i?-1:1));
}

void dfs(int v){
    dp[v] = 0;
    
    FOR(i,0,2)
        for(auto u : tree[v][i]) {
            dfs0(u,v);
            dp[v] += dp[u] + i;
        }

    FOR(i,0,2)
        for(auto u : tree[v][i])
            dfs1(u,v,dp[v] - dp[u] + (i?-1:1));
        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,v,u;
    cin >> n;
    FOR(i,1,n){
        cin >> v >> u;
        tree[v][0].pb(u);
        tree[u][1].pb(v);
    }
    dfs(1);
    auto comp = [](pii x,pii y){ return (x.F==y.F?x.S>y.S:x.F>y.F);}; 
    priority_queue<pii,vii,decltype(comp)> s(comp);
    F0R(i,1,n)
        s.push(mp(dp[i],i));
    pii x = s.top();s.pop();
    cout << x.F << endl << x.S << " ";
    while(s.size()){
        pii w = s.top();s.pop();
        if( w.F>x.F ) break;
        cout << w.S << " ";
    }
    cout << endl;
    return 0;
}
