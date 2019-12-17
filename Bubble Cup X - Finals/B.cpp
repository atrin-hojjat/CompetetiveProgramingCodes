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

const int MAXN = 1e6+10;
const int MAXL = 1e5+10;
const int MOD = 1e9+7;
const int MAXM = 105;
int in[MAXN],out[MAXN],mid[MAXN];
unsigned int num[MAXM];
ll dp[MAXM][2];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,l;
    cin >> n >> l >> m;
    bool b = false;
    FOR(i,0,n)
        cin>>in[i];
    FOR(i,0,n){
        cin >> mid[i];
        num[mid[i]]++;
    }
    FOR(i,0,n)
        cin >> out[i];
    FOR(i,0,n)
        dp[in[i]%m][b]++;
    FOR(i,1,l-1){
        FOR(j,0,m)
            FOR(x,0,m)
                dp[(j+x)%m][!b] += (num[x]*dp[j][b])%MOD;
        b = !b;
    }
    ll ans = 0;
    FOR(i,0,n)
        ans = (ans + dp[(3*m - out[i] - mid[i])%m][b])%MOD;
    cout << ans << endl;
    return 0;
}
