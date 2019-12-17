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

const int MAXN = 350;
const int LOGMAXN = 10;
piii edges[MAXN];
int xx[MAXN][MAXN];
set<pii> ed;
vii tree[MAXN];
int ans = 0;
int p[MAXN][LOGMAXN];
int h[MAXN];
int root[MAXN];
bool in_mst[MAXN];
int dis[MAXN][LOGMAXN];

int get_root(int v){
    return (root[v] ? root[v] = get_root(root[v]) : v);
}

void merge(int e){
    int rv = get_root(edges[e].S.F);
    int ru = get_root(edges[e].S.S);

    if(rv == ru)
        return ;


    root[ru] = rv;

    in_mst[e] = true;
    ans += edges[e].F;
}

void dfs(int v,int par,int hei,int e) {
    p[v][0] = par;
    dis[v][0] = edges[e].F;
    h[v] = hei;


    for(auto u : tree[v])
        if(u.S != par && in_mst[u.F])
            dfs(u.S,v,hei+1,u.F);

}

int LCA(int u,int v){
    if(h[u] < h[v]) 
        swap(v,u);
    int k = h[u]-  h[v];

    RF0R(i,0,LOGMAXN)
        if((1<<i) & k )
            u = p[u][i];

            if(u==v)
                        return v;
        RF0R(i,0,LOGMAXN)
                    if( h[v] >= 1<<i && h[u] >= 1<<i && p[u][i] != p[v][i] )
                                    v = p[v][i] , u = p[u][i];

            
                return p[u][0];


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    int k = 1;
    F0R(i,1,N)
        F0R(j,1,N) {
            int x;
            cin >> x;
            xx[i][j] = x;
            if(i==j || xx[j][i])continue;
            edges[k] = mp(x,mp(i,j));
            ed.insert(mp(x,k));
            tree[i].pb(mp(k,j));
            tree[j].pb(mp(k,i));
            k++;
        }

    for(auto x : ed)
        merge(x.S);

    dfs(1,0,0,0);

    FOR(i,1,LOGMAXN)
        F0R(j,1,N){
            p[j][i] = p[p[j][i-1]][i-1];
            dis[j][i] = dis[j][i-1] + dis[p[j][i-1]][i-1];
        }

    F0R(i,1,N)
        F0R(j,1,N){
            if(i==j)continue;
            int w = LCA(i,j);
            int d = 0;
            int k = h[i] - h[w];
            int zz = i;
            FOR(q,0,2){
                F0R(f,0,LOGMAXN)
                    if((1<<f) & k){
                        d += dis[zz][f];
                        zz = p[zz][f];
                    }

                k = h[j] - h[w];
                zz = j;
            }
            if(d != xx[i][j])
            {
                cout << i << " " << j << endl;
                cout << -1 << endl;
                return 0;
            }

        }
    cout << ans << endl;
    return 0;
}
