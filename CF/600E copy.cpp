#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

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

const int MAXN = 1e5+1;
map<int,int> cols[MAXN];
ll ans[MAXN];
int col[MAXN];
vi tree[MAXN];
int n,x,w;

void merge(int v,int u,set<pii>*s){
    for(auto w : cols[u]){
        cols[v][w.F] += w.S;
        s->insert(mp(cols[v][w.F],w.F));
    }
}

void dfs(int v,int prnt){
    cols[v][col[v]]++;
    set<pii> *s = new set<pii>();
    s->insert(mp(1,col[v]));

    for(auto u : tree[v]){
        if(u==prnt)continue;
        dfs(u,v);
        merge(v,u,s);
    }

    ans[v] = 0LL;
    w = -1;

    for(set<pii>::reverse_iterator it = s->rbegin();it!=s->rend();++it){
        if(w > 0 && w != it->F) break;
        ans[v] += it->S;
        if(w <0 )w = it->F;
    }

    delete s;
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
    F0R(i,1,n)
        tree[i].shrink_to_fit();
    dfs(1,0);
    F0R(i,1,n)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
