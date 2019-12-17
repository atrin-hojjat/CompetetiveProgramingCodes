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
const int LOGMAXN = 24;
int root[MAXN];
int root2[MAXN];
vii tree[MAXN];
piii edges[MAXN];
bool in_mst[MAXN];
int mx[MAXN][LOGMAXN];
int p[MAXN][LOGMAXN];
int h[MAXN];
ll cMST = 0;
set<pii> emst;
int stat[MAXN];
multiset<int> rm[MAXN];
map<int,int> m[MAXN];
//int MXH[MAXN][MAXN];
//set<int> heis[MAXN];

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

int lca(int&v,int&u){
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
    if(h[v]< h[u])
        swap(u,v);
    while(v != u){
        int lg = log(h[v] - h[u])/log(2);
        ans = max(ans,mx[v][lg]);
        v = p[v][lg];
    }
    return ans;
}

int get_root2(int v){
    return (root2[v] ? root2[v] = get_root2(root2[v]) : v);
}

void merge2(int v,int u){
    int rv = get_root2(v);
    int ru = get_root2(u);

    if(m[rv].size() < m[ru].size())
        swap(rv,ru);

    for(auto x : m[ru])
        if(m[rv][x.F])
            m[rv][x.F] = min(x.S,m[rv][x.F]);
        else
            m[rv][x.F] = x.S;
/*
    if(heis[rv].size() < heis[ru].size())
        swap(rv,ru);

    for(auto x : heis[ru]){
        heis[rv].insert(x);
        MXH[rv][x] = MXH[ru][x];
    }
    */

    root2[ru] = rv;
}

void dfs2(int v,int prnt,int e){

    for(pii e : tree[v])
        if(e.F != prnt && in_mst[e.S]){
            dfs2(e.F,v,e.S);
            merge2(v,e.F);
        }

    map<int,int>::iterator it = m[get_root2(v)].lower_bound(edges[e].F);
    if(it->F<=edges[e].F && it->S && it!=m[get_root2(v)].end() && h[v] >= it->S)
        stat[e] = 2;
    else 
        stat[e] = 1;
        
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;

    F0R(i,1,m){
        int x,y,z;
        cin >> x >> y >> z;
        tree[x].pb(mp(y,i));
        tree[y].pb(mp(x,i));
        edges[i] = mp(z,mp(x,y));
        emst.insert(mp(z,i));
    }
    
    MST_INIT();
    LCA_INIT(n);

    F0R(i,1,m) {
        if(in_mst[i])
            continue;
        int v = edges[i].S.F;
        int u = edges[i].S.S;
        int v1 = edges[i].S.F;
        int u1 = edges[i].S.S;
        int w = lca(v1,u1);

        int ans = max(find_max(v,w),find_max(u,w));
        if( ans >= edges[i].F ) {
            stat[i] = 2;
            int cc = edges[i].F;
            if(::m[v][cc])
                ::m[v][cc] = min(1+h[w],::m[v][cc]);
            else
                ::m[v][cc] = 1+h[w];

            if(::m[u][cc])
                ::m[u][cc] = min(1+h[w],::m[u][cc]);
            else
                ::m[u][cc] = 1+h[w];
/*
            MXH[v][h[w]] = cc;
            MXH[u][h[w]] = cc;
            heis[v].insert(h[w]);
            heis[u].insert(h[w]);
            */
        }
    }
    
    dfs2(1,0,0);

    F0R(i,1,m)
        if(stat[i] == 1)
            cout << "any\n";
        else if( stat[i] == 2 )
            cout << "at least one\n";
        else
            cout << "none\n";
    return 0;
}
