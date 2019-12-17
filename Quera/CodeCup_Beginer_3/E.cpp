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

const int MAXN = 11;
const int MAXM = 10010;
int a[MAXN];
int dp[MAXN][MAXM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,n)
        cin >> a[i];
    FOR(i,0,n) 
        FOR(j,0,10001)
            dp[i][j] = 1e9+10;
    FOR(i,0,101) {
        int ww = a[0] - i;
        dp[0][i*i] = ww*ww;
    }
    FOR(i,1,n) {
        FOR(j,0,10001) {
            FOR(k,0,101) {
                if(k*k>=j)
                    break;
                int zz = a[i] - k;
                dp[i][j] = min(dp[i][j],zz*zz+dp[i-1][j-k*k]);
            }
        }
    }
    if(dp[n-1][m]<1e9+1)
        cout << dp[n-1][m] << endl;
    else 
        cout << -1 << endl;

    return 0;
}
