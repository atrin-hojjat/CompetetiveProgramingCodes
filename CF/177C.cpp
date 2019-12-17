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

const int MAXN = 3e4+100;
int root[MAXN],sz[MAXN];
bool mark[MAXN];

int get_root(int u){
    return (root[u]?root[u] = get_root(root[u]) : u);
}

void merge(int u,int v){
    int ru = get_root(u);
    int rv = get_root(v);
    if(rv==ru) return ;
    root[ru] = rv;
    sz[rv] += sz[ru];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k,m,x,y;
    cin >> n >> k;
    fill(sz+1,sz+n+1,1);
    FOR(i,0,k){
        cin >> x >> y;
        merge(x,y);
    }
    cin >> m;
    FOR(i,0,m){
        cin >> x >> y;
        if(get_root(x)==get_root(y))
            mark[get_root(y)] = true;
    }
    int ans = 0;
    F0R(i,1,n){
        int r = get_root(i);
        if(mark[r]) continue;
        ans = max(ans,sz[r]);
        mark[r] = true;
    }
    cout << ans << endl;
    return 0;
}
