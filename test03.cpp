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

const int MAXN = 210;
const int INF = 5e9+10;
vii g[MAXN];
int dis[MAXN][MAXN];
int ro[MAXN];
int tmp[MAXN];

int brute_force(int x,bool*mark,int n,int ans,int prev) {
    if(x> n)
        return ans;
    int a = INF;
    FOR(i,0,n) {
        if(mark[i]) continue;
        mark[i] = true;
        a = min(a,brute_force(x+1,mark,n,ans+dis[ro[i]][prev],ro[i]));
        mark[i] = false;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,r;
    cin >> n >> m >> r;
    FOR(i,0,r)
        cin >> ro[i];
    FOR(i,0,m) {
        int x,y,z;
        cin >> x >> y >> z;
        g[x].pb(mp(y,z));
        g[y].pb(mp(x,z));
    }
    F0R(i,1,n) { 
        fill(tmp,tmp+1+n,INF);
        tmp[i] = 0;
        FOR(j,0,n) {
            int mn = INF,pos = 0;
            F0R(k,1,n)
                if(tmp[k]>-1 && tmp[k] < mn)
                    mn = tmp[k],pos = k;
            if(!pos)break;
            dis[i][pos] = tmp[pos];
            tmp[pos] = -1;
            for(auto w : g[pos])
                tmp[w.F] = min(tmp[w.F],w.S+dis[i][pos]);
        }
    }
    bool mark[9];
    fill(mark,mark+9,false);
    cout << brute_force(1,&mark[0],r,0,0) << endl;
    return 0;
}
