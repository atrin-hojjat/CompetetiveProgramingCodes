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
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5+10;
const int LOGMAXN = 21;
int P[MAXN][LOGMAXN];
vi tree[MAXN][LOGMAXN];

void _init_(int n){
    F0R(i,1,n) {
        cin >> P[i][0];
        if(P[i][0])
            tree[P[i][0]][0].pb(i);
    }
    FOR(i,1,LOGMAXN)
        F0R(j,1,n){
            P[j][i] = P[P[j][i-1]][i-1];
            if(P[j][i])
                tree[P[j][i]][i].pb(j);
        }
}

int dfs(int v,int x) {
    if(v==0)
        return 0;
    if(x==0)
        return 1;
    if(__builtin_popcount(x)==1)
        return tree[v][__builtin_ctz(x)].size();
    int ans = 0;
    
    for(auto u : tree[v][__builtin_ctz(x)])
        ans += dfs(u,x^(x&-x));

    return ans;
}

int get_par(int v,int x) {
    int par = v;
    while ( x > 0 )
        par = P[par][__builtin_ctz(x)],x^=x&-x;
    return par;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,Q,v,x;
    cin >> n;
    _init_(n);

    cin >> Q;

    while(Q--) {
        cin >> v >> x;
        int p = get_par(v,x);
        int ans = dfs(p,x);
        cout << (ans? ans-1 : ans) << " ";
    }
    cout << endl;
    return 0;
}
