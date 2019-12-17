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
typedef vector<piii> viii;
typedef vector<ll> vl;

const ll  INF  = 3e18+10;
const int MAXN = 1e5+100;
const int MAXM = 3e5+100;
vii g[MAXN];
vii trains;
int in_deg[MAXN];
bool mark[MAXN];
ll dis[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    FOR(i,0,m) {
        int x,y,z;
        cin >> x >> y >> z;
        g[x].pb(mp(z,y));
        g[y].pb(mp(z,x));
    }
    FOR(i,0,k) {
        int x,y;
        cin >> x >> y;
        g[1].pb(mp(y,x));
        trains.pb(mp(x,y));
    }
    fill(dis,dis+n+10,INF);
    priority_queue<pii,vii,greater<pii>> q;
    dis[1] = 0;
    q.push({dis[1],1});
    while(q.size()) {
        int u = q.top().S;
        q.pop();
        if(mark[u])continue;
        mark[u] = true;
        for(auto v : g[u] )
            if(dis[v.S] > dis[u] + v.F) {
                dis[v.S] = dis[u] + v.F;
                q.push({dis[v.S],v.S});
            }
    }
    F0R(i,1,n)
        for(auto v : g[i])
            if(dis[v.S] == dis[i] + v.F) {
               in_deg[v.S]++;
            }
    int ans = 0;
    for(auto u : trains)
        if(dis[u.F] < u.S)ans++;
        else if( in_deg[u.F]>1)ans++,in_deg[u.F]--;
    cout << ans << endl;
    return 0;
}
