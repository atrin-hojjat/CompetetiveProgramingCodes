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

const int MAXN = 105;
const int MAXX = 11;
int A[MAXN],B[MAXN];
int dp[MAXN][MAXX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,X,Y,Z;
    cin >> n >> X >> Y >> Z;
    FOR(i,0,n)
        cin >> A[i] >> B[i];
    FOR(i,0,MAXX)
        if( A[0] > i ) 
            dp[0][i] = Y * (A[0] - i);
        else 
            dp[0][i] = X * (i - A[0]);
    FOR(i,1,n) {
        FOR(j,0,MAXX) {
            if( A[i] > i ) 
                dp[i][j] = Y * (A[i] - j);
            else 
                dp[i][j] = X * (j - A[i]);
            
            
        }
        ans += dp[i][B[i]];
    }
    return 0;
}
