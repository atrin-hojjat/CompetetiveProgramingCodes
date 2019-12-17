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

const ll MOD = 1e9+7;
const int MAXN = 2020;
ll dp[MAXN][MAXN][3];

ll calc(string a,int m,int d){
    F0R(i,1,a.size())
        FOR(k,0,m)
            dp[i][k][0] = dp[i][k][1] = dp[i][k][2] = 0;
    dp[0][0][1] = 1;

    FOR(i,0,a.size()){
        FOR(k,0,m){
            if(i%2){
                dp[i+1][(k*10+d)%m][0] = (dp[i][k][0] + dp[i+1][(k*10+d)%m][0])%MOD;
                dp[i+1][(k*10+d)%m][2] = (dp[i][k][2] + dp[i+1][(k*10+d)%m][2])%MOD;
                if(a[i]-'0' == d)
                    dp[i+1][(k*10+d)%m][1] = (dp[i+1][(k*10+d)%m][1] + dp[i][k][1])%MOD;
                else if(a[i]-'0' > d)
                   dp[i+1][(k*10+d)%m][0] = (dp[i][k][1] + dp[i+1][(k*10+d)%m][0]);
                else
                   dp[i+1][(k*10+d)%m][2] = (dp[i][k][1] + dp[i+1][(k*10+d)%m][2]);
            } else {
                FOR(j,0,a[i]-'0')
                    if(j!=d){
                        dp[i+1][(k*10+j)%m][0] = (dp[i][k][0] + dp[i][k][1] + dp[i+1][(k*10+j)%m][0])%MOD;
                        dp[i+1][(k*10+j)%m][2] = (dp[i][k][2] + dp[i+1][(k*10+j)%m][2])%MOD;
                    }
                if(a[i]-'0'!=d){
                    dp[i+1][(k*10+a[i]-'0')%m][1] = (dp[i+1][(k*10+a[i]-'0')%m][1] + dp[i][k][1])%MOD;
                    dp[i+1][(k*10+a[i]-'0')%m][0] = (dp[i][k][0] + dp[i+1][(k*10+a[i]-'0')%m][0])%MOD;
                    dp[i+1][(k*10+a[i]-'0')%m][2] = (dp[i][k][2] + dp[i+1][(k*10+a[i]-'0')%m][2])%MOD;
                }

                FOR(j,a[i]-'0'+1,10)
                    if(j!=d){
                        dp[i+1][(k*10+j)%m][0] = (dp[i][k][0] + dp[i+1][(k*10+j)%m][0])%MOD;
                        dp[i+1][(k*10+j)%m][2] = (dp[i][k][2] + dp[i][k][1] + dp[i+1][(k*10+j)%m][2])%MOD;
                    }
            }
        }
    }

    ll ans = 0;
    F0R(i,1,a.size())
        ans = (ans + dp[i][0][0] + dp[i][0][1] + dp[i][0][2])%MOD;

    ans = (MOD + ans - dp[a.size()][0][2])%MOD;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int d,m;
    string a,b;
    cin >> m >> d >> a >> b ;

    bool ok = true;
    int mod = 0;

    FOR(i,0,a.size()){
        ok &= (i%2==0?a[i]-'0'!=d: a[i]-'0'==d);
        mod = (mod*10+a[i]-'0')%m;
    }

    ll ans = (MOD + (mod==0&&ok) + calc(b,m,d) - calc(a,m,d))%MOD;
    cout << ans << endl;
    return 0;
}
