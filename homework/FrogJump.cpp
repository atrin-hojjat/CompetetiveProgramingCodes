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

const int MAXN = 3e5+2;
const int MAXP = 101;
const ll INF = -6e16-66;
int arr[MAXN];
ll dp[MAXN][MAXP];
ll mx[MAXP];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k,p;
    cin >> n >> k >> p;
    FOR(i,0,n)
        cin >> arr[i];
    FOR(i,0,n)
        FOR(j,0,p+1)
            dp[i][j] = INF;
    FOR(i,0,p+1)
        mx[i] = INF;
    mx[0] = dp[0][0] = arr[0];
    FOR(i,1,n) {
        RF0R(j,1,p) {
            dp[i][j] = max(dp[i][j],max((mx[j-1]<=INF?INF*2:mx[j-1]),
                        i>=k?(dp[(i-k)][j-1]<=INF?INF*2:dp[i-k][j-1]):2*INF)+arr[i]*1LL);
            mx[j] = max(dp[i][j],mx[j]);
        }
        if(i%k==0) {
            FOR(j,0,p+1)
                mx[j] = INF;
            FOR(w,1,k)
                F0R(j,1,p)
                    dp[i-w][j] = max(dp[i-w+1][j],dp[i-w][j]);
        }
    }
    if(dp[n-1][p]<INF+1)
        cout << "Impossible" << endl;
    else 
        cout << dp[n-1][p] << endl;
    return 0;
}
