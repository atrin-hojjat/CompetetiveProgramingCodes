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
ll *ans;
int col[MAXN];
vi tree[MAXN];
int n,x,w;

void merge(map<int,int>&v,map<int,int>&u){
    for(auto w : u)
        v[w.F] += w.S;
}

void dfs(int v,int prnt,map<int,int>&m){
    map<int,int> temp;
    set<pii> max_cols;
    m[col[v]]++;

    for(auto u : tree[v]){
        if(u==prnt)continue;
        temp.clear();
        dfs(u,v,temp);
        merge(m,temp);
    }

    for(auto u : m)
        max_cols.insert(mp(u.S,u.F));

    ans[v] = 0LL;
    w = -1;

    for(set<pii>::reverse_iterator it = max_cols.rbegin();it!=max_cols.rend();++it){
        if(w > 0 && w != it->F) break;
        ans[v] += it->S;
        if(w <0 )w = it->F;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    n = 1;
    cin >> n; 
    //ans = new ll[n+1];
    ans = (ll*) malloc((n+1)*sizeof(ll));
    F0R(i,1,n)cin >> col[i];
    FOR(i,1,n){
        cin >> x >> w;
        tree[x].pb(w);
        tree[w].pb(x);
    }
    map<int,int> m;
    dfs(1,0,m);
    F0R(i,1,n)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
