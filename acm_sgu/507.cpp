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

const int MAXN = 5e4 +100;
const int base_delta = 2147483647; 
int val[MAXN],ans[MAXN],mans[MAXN];
int n,m;
multiset<int> q[MAXN];
vi tree[MAXN];
int root[MAXN];

int get_root(int v){
    return (root[v] ? root[v] = get_root(root[v]) : v);
}

void merge(int v,int u){
    int rv = get_root(v);
    int ru = get_root(u);
    if(q[rv].size() < q[ru].size())
        swap(rv,ru);
    root[ru] = rv;
    ans[rv] = min(ans[rv],ans[ru]);
    for(auto x : q[ru]){
        q[rv].insert(x);
        multiset<int>::iterator z = q[rv].find(x),a1 = z,a2 = z; 
        if(a1 != q[rv].begin())
            ans[rv] = min(ans[rv], abs(*--a1 - x));
        if(++a2 != q[rv].end())
            ans[rv] = min(ans[rv], abs(*a2 - x));
    }
}

void dfs(int v){
    ans[v] = base_delta;
    if(v > n-m){
        q[v].insert(val[v]);
        return;
    }
    for(auto u : tree[v]){
        dfs(u);
        merge(v,u);
    }
    int rv = get_root(v);
    mans[v] = ans[rv];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int x;

    cin >> n >> m;

    F0R(i,2,n){
        cin >> x;
        tree[x].pb(i);
    }
    F0R(i,n-m+1,n)
        cin >> val[i];

    dfs(1);
    F0R(i,1,n-m)
        cout << mans[i] << " " ;
    cout << endl;
    return 0;
}
