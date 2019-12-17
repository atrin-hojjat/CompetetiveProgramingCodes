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

const int MAXN = 510;
const int MAXM = 1e4+10;
vii g[MAXN];
bool mark[MAXN];
bool mark_true = true;

void dfs(int v,int l,int r) {
    //if(mark[v] == mark_true)return;
    mark[v] = !mark[v];
    for(auto u : g[v])
        if((u.S<l || u.S>r) && mark[u.F]!=mark_true)
            dfs(u.F,l,r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    F0R(i,1,m) {
        int x,y;
        cin >> x >> y;
        g[x].pb(mp(y,i));
        g[y].pb(mp(x,i));
    }
    int k;
    cin >> k ;
    while(k--) {
        int l,r,c=0;
        cin >> l >> r;
        F0R(i,1,n)
            if(mark[i] != mark_true)
                dfs(i,l,r),c++;
        cout << c << "\n";
        mark_true = !mark_true;
    }
    return 0;
}
