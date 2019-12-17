#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
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
double arr[MAXN][MAXN];
double dp[1<<MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n)
        FOR(j,0,n)
            cin >> arr[i][j];
    dp[0] = 1;
    FOR(mask,1,1<<n) {
        int w = __builtin_popcount(mask);
        double ww= w*(w+1)/2;
        FOR(i,0,n)
            FOR(j,0,n)
                if(i!=j && (mask&(1<<i))==0 && (mask&(1<<j))) {
                  dp[mask]  += dp[mask^(1<<j)] * arr[i][j]/ww;
                }
    }
    cout  << fixed << setprecision(8); 
    FOR(i,0,n) {
        int pos = ((1<<n)-1)^(1<<i);
        cout << dp[pos] << " ";
    }
    cout << endl;
    return 0;
}
