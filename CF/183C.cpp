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
#include <numeric>

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

const int MAXN = 100100;
bool mark[MAXN];
set<int> g[MAXN];
set<int> gi[MAXN];
ll c[MAXN];
ll n;
ll k;

ll gcd(ll x,ll y) {
    return (y?gcd(y,x%y):x);
}

void dfs(int v,int col) {
    if(mark[v])return;
    mark[v] = true;
    int ww = k?k:n;
    c[v] = (col+ww)%ww;

    for(auto u : g[v]) 
        if( mark[u] ) {
            if(k==0) k = abs(c[v]+1-c[u]);
            else k = gcd(k,abs(c[v]+1-c[u]));
        } else dfs(u,col+1);
    for(auto u : gi[v]) 
        if( mark[u] ) {
            if(k==0) k = abs(c[u]+1-c[v]);
            else k = gcd(k,abs(c[u]+1-c[v]));
        } else dfs(u,col-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int m;
    cin >> n >> m ;
    FOR(i,0,m) {
        int x,y;
        cin >> x >> y;
        g[x].insert(y);
        gi[y].insert(x);
    }
    F0R(i,1,n)
        if(!mark[i])
            dfs(i,0);
    cout << (k==0?n:k) << endl;
    return 0;
}
