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

const int MAXN = 2e5+66.6;
const int LOGMAXN = 20;
const int INF = 2e9+6.66;
vi tree[MAXN];
int l[MAXN],f[MAXN];
int h[MAXN];
int RMQ[MAXN*2][LOGMAXN];
int sz = 0;

void dfs(int v,int prnt=0) {
    h[v] = h[prnt]+1;
    
    f[v] = sz;
    RMQ[sz++][0] = v;
    for(auto u : tree[v])
        if(u!=prnt)
            dfs(u,v),RMQ[sz++][0] = v;
    l[v] = sz-1;
}

void INIT_RMQ(int n){
    h[0] = INF;
    FOR(j,1,LOGMAXN)
        FOR(i,0,sz){
            if(i+(1<<j)>=sz)continue;
            if(h[RMQ[i][j-1]] > h[RMQ[i+(1<<(j-1))][j-1]])
                RMQ[i][j] = RMQ[i+ (1<<(j-1))][j-1];
            else 
                RMQ[i][j] = RMQ[i][j-1];
        }
}

int lca(int a,int b) {
    if(f[b]< f[a])swap(a,b);
    int w = f[b] - f[a];
    int lg = (w==0?w : log(w)/log(2));
    int l1 = RMQ[f[a]][lg],l2 = RMQ[f[b]-(1<<lg)+1][lg];
    return h[l1]>h[l2] ? l2 : l1;
}

int solve(int a,int b,int c) {
    int l1 = lca(a,b);
    int l2 = lca(b,c);
    int l3 = lca(c,a);
    int l = l1;
    if(h[l] < h[l2])l = l2;
    if(h[l] < h[l3])l = l3;
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,1,n) {
        int x,y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(1);
    INIT_RMQ(n);
    int q;
    cin >> q;
    while(q--) {
        int a,b,c;
        cin >> a >> b >> c;
        cout << solve(a,b,c) << endl;
    }
    return 0;
}
