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

const int MAXN = 250;
vi tree[MAXN];
vii edges;

int dfs1(int v,int prnt){
    int mx = 0;
    for(auto u : tree[v])
        if(u != prnt)
            mx = max(mx,dfs1(u,v));
    return mx+1;
}

int dfs(int v,int prnt){
    int x,m = 0,mx[2] = {0,0},temp;
    for(auto u : tree[v])
        if(u != prnt){
            m = max(m,dfs(u,v));
            x = dfs1(u,v);
            FOR(i,0,2)
                if(x>mx[i])
                    swap(x,mx[i]);
        }
    if(tree[v].size() == 1)
        return 1;
    else if(tree[v].size() == 2)
        return max(m,1+mx[0]);
    else 
        return max(m,mx[1] + mx[0] + 1);
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
        edges.pb(mp(x,y));
    }
    int ans = 0;
    for(auto e : edges)
        ans = max(ans,(dfs(e.F,e.S)-1)*(dfs(e.S,e.F)-1));
    cout << ans << endl;
    return 0;
}
