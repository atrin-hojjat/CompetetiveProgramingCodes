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
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 2e5 + 100;
const int LOGMAXN = 20;
int root[MAXN];
vii tree[MAXN];
piii edges[MAXN];
bool in_mst[MAXN];
int mx[MAXN][LOGMAXN];
int p[MAXN][LOGMAXN];
int h[MAXN];
ll cMST = 0;
set<pii> emst;

int get_root(int v){
    return (root[v] ? root[v] = get_root(root[v]) : v);
}

void merge(int e){
    pii edge = edges[e].S;
    int ru = get_root(edge.F);
    int rv = get_root(edge.S);

    if(ru == rv)
        return ;

    root[ru] = rv;
    in_mst[e] = true;
    cMST += edges[e].F;
}

void MST_INIT() {
    cMST = 0;
    for(auto e : emst)
        merge(e.S);
}

void dfs(int v,int prnt,int hei,int in_edge){
    p[v][0] = prnt;
    mx[v][0] = in_edge;
    h[v] = hei;

    for(pii e : tree[v])
        if(e.F != prnt && in_mst[e.S])
            dfs(e.F,v,hei+1,edges[e.S].F);
}

void LCA_INIT(int n){
    dfs(1,0,0,0);

    for(int i = 1;(1<<i) <= n;i++)
        F0R(j,1,n)
            if(h[j] >= (1<<i)) {
                p[j][i] = p[p[j][i-1]][i-1];
                mx[j][i] = max(mx[j][i-1],mx[p[j][i-1]][i-1]);
            }
}

int lca(int v,int u){
    if(h[v] > h[u] )
        swap(v,u);

    int lg = log(h[u])/log(2);

    RF0R(i,0,lg)
        if( h[u] - (1<<i) >= h[v] )
            u = p[u][i];

    if( u == v )
        return v;

    RF0R(i,0,lg)
        if(h[v] >= (1<<i) && h[u] >= (1<<i)  && p[v][i] != p[u][i])
            u = p[u][i] ,v = p[v][i];

    return p[v][0];
}

int find_max(int v,int u){
    int ans = 0;
    while(v != u){
        int lg = log(h[v] - h[u])/log(2);
        ans = max(ans,mx[v][lg]);
        v = p[v][lg];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;

    FOR(i,0,m){
        int x,y,z;
        cin >> x >> y >> z;
        tree[x].pb(mp(y,i));
        tree[y].pb(mp(x,i));
        edges[i] = mp(z,mp(x,y));
        emst.insert(mp(z,i));
    }
    
    MST_INIT();
    LCA_INIT(n);

    FOR(i,0,m) {
        if(in_mst[i]){
            cout << cMST << "\n";
            continue;
        }
        int v = edges[i].S.F;
        int u = edges[i].S.S;
        int w = lca(v,u);

        int ans = max(find_max(v,w),find_max(u,w));
        cout << cMST - ans  + edges[i].F << "\n";
    }
    
    return 0;
}
