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

const int MAXN = 4e5+100;
const int INF  = 4e5+100;
bool c[MAXN];
vi tree[MAXN];
vi new_tree[MAXN];
int height[MAXN];
pii dp[MAXN][2];
int n,ind = 0;

void dfs(int v,int prev,int index){

    for(auto u : tree[v])
        if(u!=prev){
            if(c[v]!=c[u]){
                new_tree[index].pb(++ind);
                new_tree[ind].pb(index);
                dfs(u,v,ind);
            } else
                dfs(u,v,index);
        }

}

int dfs_lpath(int v,int prev){
    
    for(auto u : new_tree[v])
        if(u!=prev){
            pii temp = mp(dfs_lpath(u,v),u);
            if(temp.F>dp[v][0].F){
                swap(temp,dp[v][0]);
                swap(temp,dp[v][1]);
            } else if (temp.F>dp[v][1].F)
                swap(dp[v][1],temp);
        }

    return dp[v][0].F+1;
}

void calc_height(int v,int prev,int h1){
    height[v] = max(h1,dp[v][0].F);

    int temp = prev;
    if(h1<dp[v][0].F)
        temp = dp[v][0] .S;

    for(auto u : new_tree[v])
        if(u!=prev)
            calc_height(u,v,(u==temp? max(dp[v][1].F,h1)+1 : height[v]+1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int x,y;
    cin >> n;
    F0R(i,1,n)
        cin >> c[i];
    FOR(i,1,n){
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(1,-1,++ind);
    dfs_lpath(1,-1);
    calc_height(1,-1,0);
    int ans = INF;
    F0R(i,1,ind)
        ans = min(ans,height[i]);
    cout << ans << endl;
    return 0;
}
