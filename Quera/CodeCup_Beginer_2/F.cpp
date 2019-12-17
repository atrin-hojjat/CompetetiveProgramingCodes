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
#include <stack>

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

const int MAXN = 1e5+10;
const int LOGMAXN = 20;
vector<pair<int,ll>> tree[MAXN];
int h[MAXN];
int P[MAXN][LOGMAXN];
ll sum[MAXN][LOGMAXN];
ll mxsum[MAXN][LOGMAXN];
ll sumup[MAXN][LOGMAXN];
ll sumdown[MAXN][LOGMAXN];

void dfs(int v,int p,ll w,int hei) {
    h[v] = hei;
    P[v][0] = p;
    sum[v][0] = w;
    sumdown[v][0]  = sumup[v][0] = mxsum[v][0] = max(w,0LL);

    FOR(i,1,LOGMAXN) {
        P[v][i] = P[P[v][i-1]][i-1];
        sum[v][i] = sum[v][i-1] + sum[P[v][i-1]][i-1];
        sumdown[v][i] = max(sumdown[P[v][i-1]][i-1],sum[P[v][i-1]][i-1]+sumdown[v][i-1]);
        sumup[v][i] = max(sumup[v][i-1],sum[v][i-1] + sumup[P[v][i-1]][i-1]);
        mxsum[v][i] = max({mxsum[v][i-1],mxsum[P[v][i-1]][i-1],
                sumup[P[v][i-1]][i-1] + sumdown[v][i-1]});
    }

    for(auto u : tree[v])
        if(u.F!=p)
            dfs(u.F,v,u.S,hei+1);
}

int get_par(int v,int h) {
    while(h) {
        v = P[v][__builtin_ctz(h)],h^=h&-h;
    }
    return v;
}

int lca(int v,int u) {
    if(h[v] > h[u])
        swap(v,u);

    u = get_par(u,h[u]-h[v]);

    if(u==v)
        return v;

    RFOR(i,0,LOGMAXN)
        if(P[v][i]!=P[u][i])
            u = P[u][i],v = P[v][i];

    return P[v][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    FOR(i,1,n) {
        int x,y;
        ll z;
        cin >> x >> y >> z;
        tree[x].pb(mp(y,z));
        tree[y].pb(mp(x,z));
    }
    dfs(1,0,0,0);
    while(q--) {
        int u,v,w;
        cin >> u >> v;
        w = lca(u,v);
        ll ans = 0,ans1[2] = {0,0};
        FOR(i,0,2) {
            stack<int> pars;
            int dis = h[v] - h[w];
            int tmp = dis,tv = v;
            ll mxdown = 0;
            while(tmp) {
                pars.push(tv);
                int ctz = __builtin_ctz(tmp);
                ll tt = max(mxsum[tv][ctz],sumup[tv][ctz] +mxdown);
                mxdown = max(mxdown+sum[tv][ctz],sumdown[tv][ctz]);
                ans = max(ans,tt);
                tv = P[tv][ctz],tmp^=tmp&-tmp;
            }
            ll s = 0;
            RFOR(j,0,LOGMAXN) {
                if((1<<j) &dis) {
                    int w = pars.top();
                    pars.pop();
                    ans1[i] = max(ans1[i],s+sumdown[w][j]);
                    s+= sum[w][j];
                }
            }
            swap(u,v);
        }
        ans = max(ans,ans1[0] + ans1[1]);
        cout << ans << endl;
    }
    return 0;
}
