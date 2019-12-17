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

const int MAXN      = 1e5+100;
const ll  MOD       = 1e9+7;
const int LOGMAXN   = 20;
vii g[MAXN];
bool cut[MAXN];
vi tree[MAXN];
int P[MAXN][LOGMAXN];
int cnt[MAXN][LOGMAXN];
int root[MAXN];
int h[MAXN];
bool mark[MAXN];
int d[MAXN];
int hei[MAXN];
bool is_cycle[MAXN];

ll pow(int exp) {
    ll ans = 1;
    ll pow = 2;
    while(exp) {
        if(exp&1) ans = (ans*pow)%MOD;
        pow = (pow*pow)%MOD;
        exp>>=1;
    }
    return ans;
}

void cut_dfs(int v,int height,int par) {
    if(mark[v]) return;
    hei[v] = height;
    d[v] = height;
    mark[v] = true;

    for(auto u : g[v])
        if(!mark[u.F])
        {
            cut_dfs(u.F,height+1,v);
            d[v] = min(d[v],d[u.F]);
            if(d[u.F] > hei[v])
                cut[u.S] = true;
        } else if(u.F !=par)
            d[v] = min(d[v],hei[u.F]);
}

void merge_dfs(int v,int fi,int p){
    if(!mark[v])return;
    mark[v] = false;
    root[v] = fi;

    for(auto u : g[v])
        if(u.F==fi)
            continue;
        else if(cut[u.S])
            tree[p].pb(u.F);
        else
            merge_dfs(u.F,fi,p),is_cycle[v] = true;
}

void dfs(int v,int hei,int p) {
    ::P[v][0]   = p;
    ::h[v]      = hei;
    ::cnt[v][0] = is_cycle[v];

    FOR(i,1,LOGMAXN) {
        if( (1<<i) > h[v])break;
        P[v][i] = P[P[v][i-1]][i-1];
        cnt[v][i] = cnt[v][i-1] + cnt[P[v][i-1]][i-1];
    }

    for(auto u : tree[v])
        if(root[u] != p)
            dfs(root[u],hei+1,v);
}

int get_par(int v,int x) {
    while(x) {
        int ww = __builtin_ctz(x);
        v = P[v][ww],x^=x&-x;
    }
    return v;
}

int get_cnt(int v,int x) {
    int ans = 0;
    while(x) {
        int ww = __builtin_ctz(x);
        ans+=cnt[v][ww],v = P[v][ww],x^=x&-x;
    }
    return ans;
}

int LCA(int v,int u) {
    if(h[v] > h[u])
        swap(u,v);

    u = get_par(u,h[u]-h[v]);

    if(v==u)
        return v;

    RFOR(i,0,LOGMAXN)
        if(P[v][i] != P[u][i])
            u = P[u][i],v = P[v][i];

    return P[v][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,m) {
        int x,y;
        cin >> x >> y;
        g[x].pb(mp(y,i));
        g[y].pb(mp(x,i));
    }
    cut_dfs(1,0,0);

    F0R(i,1,n) {
        if(!mark[i])continue;
        merge_dfs(i,i,i);
    }

    dfs(1,0,0);
    
    int q;
    cin >> q;
    while(q--) {
        int x,y;
        cin >> x >> y;
        x = root[x],y = root[y];
        int w = LCA(x,y);
        int tc = get_cnt(x,h[x]-h[w]) +
            get_cnt(y,h[y]-h[w]) + cnt[w][0];

//        ll ans = (1LL<<tc)%MOD;
        ll ans = pow(tc);
        cout << ans << endl;
    }
    return 0;
}
