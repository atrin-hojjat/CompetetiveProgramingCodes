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
const int LOGMAXN = 17;
vi tree[MAXN];
int p[MAXN][LOGMAXN];
int h[MAXN];
int ch[MAXN];

void dfs(int v,int prnt,int hei){
    h[v] = hei;
    p[v][0] = prnt;
    ch[v] = 1;

    for(auto u : tree[v])
        if(u != prnt)
        {
            dfs(u,v,hei+1);
            ch[v] += ch[u];
        }
}

void process_prnt(int n){
    for(int i=1; (1<<i)<=n;i++)
        F0R(j,1,n)
            p[j][i] = p[p[j][i-1]][i-1];
}

int lca(int v,int u){
    if(h[u] < h[v])
        swap(v,u);
    int lg = log(h[u])/log(2);

    RF0R(i,0,lg)
        if(h[u] - (1<< i) >= h[v])
            u = p[u][i];

    if(u==v)
        return v;

    RF0R(i,0,lg)
        if((1<<i) <= h[v] && p[v][i] != p[u][i])
            u = p[u][i],v = p[v][i];

    return p[u][0];
}

void path_to_par(int v,int prnt,int&c,int&dis){
    int lg = log(h[v])/log(2);
    dis = 0;

    RF0R(i,0,lg)
        if(h[v] - (1<< i) > h[prnt])
            v = p[v][i],dis += (1<<i);

    c = v;
    if(v!=prnt)dis+=1;
}

int ith_par(int v,int i,int&c){
    if(i==0){
        c = v;
        return c;
    }
    int lg = log(i)/log(2);

    RF0R(x,0,lg)
        if(i > (1<<x))
            v = p[v][x],i-=1<<x;
    c = v;
    return p[v][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n ;

    FOR(i,1,n){
        int x,y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    dfs(1,0,0);
    process_prnt(n);

    int m;
    cin >> m ;

    while(m--){
        int x,y;
        cin >> x >> y;

        int z = lca(x,y);
        int c1,c2,dis1,dis2;
        path_to_par(x,z,c1,dis1);
        path_to_par(y,z,c2,dis2);
        int path_len = dis1+dis2;

        if(path_len %2){
            cout << 0 << "\n";
            continue;
        }

        if(h[x] < h[y])
            swap(x,y);

        int c3;
        int par = ith_par(x,path_len/2,c3);

        if(path_len==0)
            cout << n;
        else if(par == z)
            cout << n - ch[c1] - ch[c2];
        else
            cout << ch[par] - ch[c3];
        cout << "\n";
    }

    return 0;
}
