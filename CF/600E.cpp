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
typedef priority_queue<pii> _pqpii;

const int MAXN = 1e5+1;
map<int,int> cols[MAXN];
ll ans[MAXN];
ll mans[MAXN];
int col[MAXN];
int mx[MAXN];
vi tree[MAXN];
int root[MAXN];
int n,x,w;

int get_root(int v){
    return (root[v] ? root[v] = get_root(root[v]) : v);
}

void merge(int v,int u){
    int ru = get_root(u);
    int rv = get_root(v);
    if(cols[ru].size() > cols[rv].size())
        swap(ru,rv);
    root[ru] = rv;
    for(auto w : cols[ru]){
        cols[rv][w.F] += w.S;
        if(cols[rv][w.F] > mx[rv]){
            mx[rv] = cols[rv][w.F];
            ans[rv] = w.F;
        } else if(cols[rv][w.F] == mx[rv] && w.S>0)
            ans[rv] += w.F;
    }
}

void dfs(int v,int prnt){
    cols[v][col[v]]++;
    
    ans[v] = col[v];
    mx[v] = 1;

    for(auto u : tree[v]){
        if(u==prnt)continue;
        dfs(u,v);
        merge(v,u);
    }
    mans[v] = ans[get_root(v)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n; 
    F0R(i,1,n)cin >> col[i];
    FOR(i,1,n){
        cin >> x >> w;
        tree[x].pb(w);
        tree[w].pb(x);
    }
    dfs(1,0);
    F0R(i,1,n)
        cout << mans[i] << " ";
    cout << endl;
    return 0;
}
