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
#include <iomanip>

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

const int MAXN = 50;
ll adj[MAXN];
int dp[1<<20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n,k,h,ans = 0;
    cin >> n >> k;
    h = n>>1;

    FOR(i,0,n)
        FOR(j,0,n){
            bool x;
            cin >> x;
            adj[i] |= (ll)(i==j || x)<<j;
        }

    FOR(i,0,1<<(n-h)){
        int x = i;
        FOR(j,0,n-h)
            if((i>>j)&1)
                x &= adj[j+h] >> h;

        if(x==i)dp[i] = __builtin_popcount(x);
    }

    FOR(i,0,1<<(n-h))
        FOR(j,0,n-h)
            if(1&(i>>j))
                dp[i] = max(dp[i],dp[i^(1<<j)]);

    FOR(i,0,1<<h){
        int x = i,y = (1<<(n-h)) -1;

        FOR(j,0,h)
            if((i>>j)&1){
                x &= adj[j] & ((1<<h)-1);
                y &= adj[j] >> h;
            }

        if(x==i)
            ans = max(ans,__builtin_popcount(x) + dp[y]);
    }

    long double edge = (long double) k * 1.0 / ans;
    long double stb  = (long double) ans * (ans-1) * 0.5 * edge * edge ;

    cout << fixed << setprecision(9) << stb << endl;

    return 0;
}
