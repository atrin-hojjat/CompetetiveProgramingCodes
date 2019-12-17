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

const int MAXN = 3e5 + 100;
int root[MAXN],dis[MAXN];
bool mark[MAXN];
vi tree[MAXN];

int get_root(int v){
    return (root[v]? root[v] = get_root(root[v]) : v);
}

int dfs(int v,int&w,int prnt){
    int temp,temp1,ans = 0;
    w = v;
    for(auto u : tree[v])
        if(u!=prnt){
            temp = 1 + dfs(u,temp1,v);
            if(temp > ans){
                ans = temp;
                w = temp1;
            }
        }
    return ans;
}

void dfs(int v){
    int w,z;
    dfs(v,w,-1);
    dis[v] = dfs(w,z,-1);
}

void merge1(int v,int u){
    int rv = get_root(v);
    int ru = get_root(u);
    
    if(ru == rv) return;

    root[rv] = ru;
}

void merge(int v,int u){
    int rv = get_root(v);
    int ru = get_root(u);

    if(ru==rv)return ;

    root[ru] = rv;
    dis[rv] = max(max(dis[rv],dis[ru]),
            (dis[rv]+1)/2 + (dis[ru]+1)/2 + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,q;
    int x,y,z;
    cin >> n >> m >> q;

    FOR(i,0,m){
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
        merge1(x,y);
    }

    F0R(i,1,n){
        int w = get_root(i);
        if(mark[w]) continue;
        mark[w] = true;
        dfs(w);
    }
    
    while(q--){
        cin >> x ;
        if(x==1){
            cin >> y;
            z = get_root(y);
            cout << dis[z] << "\n";
        } else {
            cin >> y >> z;
            merge(z,y);
        }
    }
    
    return 0;
}