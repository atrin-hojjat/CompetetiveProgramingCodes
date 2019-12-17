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

const int MAXN = 5e3+100;
vii tree[MAXN];
piii edges[MAXN];
int cnt[MAXN];
int n;

int dfs_count(int v,int prnt,ll&val) {
    int ans = 1;
    for(auto u : tree[v]) {
        if(u.F==prnt)continue;
        int x = dfs_count(u.F,v,val);
        val += 1LL * u.S * x * (n-x);
        ans += x;
    }
    return (cnt[v] = ans);
}

ll dfs_calc(int v,int prnt,int c0,int w,ll val) {
    ll ans = val;
    if(cnt[v]<c0)
        ans = val - 1LL*cnt[v]*(n-cnt[v])*w
            + 1LL*(c0-cnt[v])*(n-c0+cnt[v])*w;
    for(auto u : tree[v])
    {
        if(u.F==prnt)continue;
        ans = min(ans,dfs_calc(u.F,v,c0,u.S,ans));
    }
    return min(val,ans);
}

ll solve(int i) {
    ll v = 0,v1 = 0,v2=0;
    int s1 = dfs_count(edges[i].S.F,edges[i].S.S,v1);
    int s2 = dfs_count(edges[i].S.S,edges[i].S.F,v2);
    v = 1LL * edges[i].F * s1 * s2;
    v1 = dfs_calc(edges[i].S.F,edges[i].S.S,s1,edges[i].F,v1);
    v2 = dfs_calc(edges[i].S.S,edges[i].S.F,s2,edges[i].F,v2);
    v += v1+v2;
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n; 
    FOR(i,1,n) {
        int x,y,z;
        cin >> x >> y >> z;

        tree[x].pb(mp(y,z));
        tree[y].pb(mp(x,z));
        edges[i] = mp(z,mp(x,y));
    }
    
    ll ans = 1e18;
    FOR(i,1,n) {
        ans = min(ans,solve(i));
    }
    cout << ans << endl;
    return 0;
}
