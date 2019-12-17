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
const int LOGMAXN = 20;
const int MAXA = 12;
const int INF = 2e6 + 33;
int h[MAXN];
vi tree[MAXN];
int p[MAXN][LOGMAXN];
int mn[MAXN][LOGMAXN][MAXA];

void insert(int x,int *w){
    int temp = x;

    FOR(i,0,MAXA)
        if(w[i] > temp)
            swap(temp,w[i]);
}

void init_dfs(int v,int prnt,int hei){
    p[v][0] = prnt;
    h[v] = hei;

    for(auto u : tree[v])
        if(u!=prnt)
            init_dfs(u,v,hei+1);
}

int lca(int v,int u){
    
    if(h[v] < h[u])
        swap(u,v);

    int lg;// Alternatively = log(h[v])/log(2)
    for(lg = 0;(1<<lg)<=h[v];lg++);
    lg--;

    RF0R(i,0,lg)
        if(h[v] - (1<<i) >= h[u])
            v = p[v][i];

    if(u == v)
        return v;

    RF0R(i,0,lg)
        if(p[v][i] && p[v][i] != p[u][i])
            v = p[v][i],u = p[u][i];

    return p[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,q;

    cin >> n >> m >> q;

    FOR(i,1,n){
        int x,y;cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    for(int i=0;(1<<i) <= n;i++)
        F0R(j,1,n)
            FOR(k,0,MAXA)
                mn[j][i][k] = INF;

    F0R(i,1,m){
        int x;cin >> x;
        insert(i,mn[x][0]);
    }

    // INITIATE LCA
    init_dfs(1,0,0);

    for(int i=1;(1<<i) <= n;i++)
        F0R(j,1,n)
            if(h[j] >= (1<<i))
                p[j][i] = p[p[j][i-1]][i-1];

    for(int i=1;(1<<i) <= n;i++)
        F0R(j,1,n)
            if(h[j] >= (1<<i))
                FOR(k,0,MAXA){
                    insert(mn[j][i-1][k],mn[j][i]);
                    insert(mn[p[j][i-1]][i-1][k],mn[j][i]);
                }

    //Query
    int arr[MAXA];
    while(q--){
        fill(arr,arr+MAXA,INF);
        int u[2],c;
        cin >> u[0] >> u[1] >> c;

        int w = lca(u[0],u[1]);

        FOR(zz,0,2){
            int X = h[u[zz]] - h[w];
            int lg = log(X)/log(2);

            /*
            RF0R(i,0,lg)
                if(X& (1<<i)){
                    FOR(j,0,MAXA)
                        insert(mn[u[zz]][i][j],arr);
                    u[zz] = p[u[zz]][i];
                }
                */
            while(u[zz] != w){
                X = h[u[zz]] - h[w];
                lg = log(X)/log(2);
                FOR(i,0,MAXA)
                    insert(mn[u[zz]][lg][i],arr);
                u[zz] = p[u[zz]][lg];
            }
        }
        FOR(j,0,MAXA)
            insert(mn[w][0][j],arr);

        vector<int> v;

        FOR(j,0,c)
            if(arr[j] != INF)
                v.pb(arr[j]);

        cout << v.size() << " ";

        for(auto x : v)
            cout << x << " ";
        cout << "\n";

    }

    return 0;
}
