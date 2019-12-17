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

const int MAXN = 20;
ll dp[1<<MAXN][MAXN];
bool adj[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,m) {
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x][y] = adj[y][x] = 1;
    }
    ll ans = 0;
    FOR(i,0,n)
        dp[1<<i][i] = 1LL;
    FOR(mask,0,1<<n) {
        FOR(i,0,n) {
            if((mask&(1<<i))==0 || !(__builtin_popcount(mask)==1 ||
                        i!=__builtin_ctz(mask)))continue;
            FOR(j,0,n) {
                if((mask&(1<<j))==0 && adj[i][j])
                    dp[mask|(1<<j)][j] += dp[mask][i];
            }
            if(__builtin_popcount(mask)>2)
                ans+=1LL*dp[mask][i]*adj[i][__builtin_ctz(mask)];
        }
    }
    ans/=2;
    cout << ans << endl;
    return 0;
}
