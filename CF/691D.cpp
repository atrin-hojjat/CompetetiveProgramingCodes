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

const int MAXN = 1e6+10;
int p[MAXN];
int root[MAXN];
bool mark[MAXN];
vi g[MAXN];
priority_queue<int> q[MAXN];

int get_root(int v){
    return (root[v] ? root[v]=get_root(root[v]) : v);
}

void merge(int v,int u) {
    int rv = get_root(v);
    int ru = get_root(u);

    if(rv==ru)
        return ;

    if(q[rv].size()<q[ru].size())
        swap(rv,ru);

    root[ru] = rv;

    while(q[ru].size()){
        q[rv].push(q[ru].top());
        q[ru].pop();
    }
}

void dfs(int v) {
    if(mark[v])return;

    mark[v] = true;
    q[v].push(p[v]);

    for(auto u : g[v]){
        dfs(u);
        merge(u,v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,n)
        cin >> p[i+1];

    FOR(i,0,m) {
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    F0R(i,1,n) 
        if(!mark[i])dfs(i);

    F0R(i,1,n){
        int ri = get_root(i);
        cout << q[ri].top() << " ";
        q[ri].pop();
    }
    cout << endl;

    return 0;
}
