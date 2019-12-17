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

const int MAXN = 3000;
const int MOD = 1e9+7;
ll ans = 0,ansrm = 0;
int d,n;
vi tree[MAXN];
int a[MAXN];

ll dfs(int v ,int prnt,int mx,int root){
    ll ans1 = 1;

    for(auto u : tree[v])
        if(u!=prnt && a[u]<=mx && mx-a[u] <= d){
            if(a[u]==mx && u < root)continue;
            ans1 = (1LL * ans1 * (1+dfs(u,v,mx,root)))%MOD;
        }


    return ans1%MOD;
}

void dfs(int v){
    ll ans1 = 1;

    for(auto u : tree[v])
        if(a[u] <= a[v] && a[v]-a[u] <= d){
            if(a[u] == a[v] && u < v)continue;
            ans1 = (1LL * ans1 * (1+dfs(u,v,a[v],v)))%MOD;
        }

    ans = (ans + ans1)%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> d >> n;
    __in_arr__(a,1,1+n);
    
    int x,y;

    FOR(i,1,n){
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    F0R(i,1,n){
        dfs(i);
    }

    cout << ans << endl;
    return 0;
}
