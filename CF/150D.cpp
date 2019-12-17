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

const int MAXN = 150+6.66;
int dp[MAXN][MAXN][MAXN];
int rm[MAXN][MAXN];
int ans[MAXN][MAXN];
//bool pal[MAXN][MAXN];
int C[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n ;
    cin >> n;
    F0R(i,1,n)cin >> C[i];
    string str;cin >> str;

    int mx = 0;
    /*FOR(i,0,n) {
        pal[i][i] = true;
        if(i>0)pal[i-1][i] = str[i]==str[i-1];
        RFOR(j,0,i-1)
            pal[j][i] = str[i]==str[j] && pal[j+1][i-1];
    }*/
    FOR(r,0,n) {
        FOR(l,0,n) {
            F0R(len,0,n)
                dp[l][r][len] = -1;
            if(l<=r)rm[l][r] = -1;
        }
    }
    FOR(r,0,n) RF0R(l,0,r) {

        if(r==l) 
            dp[l][r][1] = 0;
        else {
            dp[l][r][1] = max({dp[l][r][1],rm[l+1][r],rm[l][r-1]});
            FOR(i,l+1,r)
                dp[l][r][1] = max(dp[l][r][1],rm[l][i-1]>=0&&rm[i+1][r]>=0?rm[l][i-1]+rm[i+1][r]:-1);
        }
        rm[l][r] = max(rm[l][r],dp[l][r][1]>=0 && C[1]>=0?dp[l][r][1]+C[1]:-1);

        F0R(len,2,r-l+1) {
            if(str[r]==str[l])
                dp[l][r][len] = (r-l+1>2?dp[l+1][r-1][len-2]:0);
            FOR(mid,l,r)
                dp[l][r][len] = max( {dp[l][r][len],
                        dp[l][mid][len]>=0 && rm[mid+1][r]>=0 && mid-l+1>=len?dp[l][mid][len] + rm[mid+1][r] : -1,
                        dp[mid+1][r][len]>=0 && rm[l][mid]>=0 && r-mid>=len?dp[mid+1][r][len] + rm[l][mid] : -1});
            if( C[len] >= 0 ) {
                rm[l][r] = max(rm[l][r],dp[l][r][len]>=0?C[len] + dp[l][r][len]:-1);
            }
        }
    //    if(pal[l][r] ) {
    //        dp[l][r][r-l+1] = 0;
    //        if(C[r-l+1]>=0)
    //            rm[l][r] = max(rm[l][r] , C[r-l+1]);
    //    }
        dp[l][r][0] = rm[l][r];

        ans[l][r] = max(rm[l][r],0);
        FOR(i,l,r)
            ans[l][r] = max(ans[l][r],ans[l][i] + ans[i+1][r]);
    }
    cout << ans[0][n-1] << endl;
    return 0;
}
