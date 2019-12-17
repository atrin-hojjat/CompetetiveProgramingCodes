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
#include <stack>
#include <deque>

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

const int MAXN = 10;
ll dp[MAXN][1<<MAXN];
int n,m;

void backtrack(int i,int j,int mask,int nmask) {
    if(j>m)return ;
    if(j==m) {
        dp[i+1][nmask] += dp[i][mask];
        return ;
    }
    if(((mask>>j)&1)) {
		backtrack(i,j+1,mask,nmask);
		return ;
	}
    if(i<n-1&&((nmask>>j)&1)==0)backtrack(i,j+1,mask,nmask|(1<<j));
    if(j<m-1&&((mask>>(j+1))&1)==0) backtrack(i,j+2,mask,nmask);
    if(i<n-1&&j<m-1&&((mask>>(j+1))&1)==0 && ((nmask>>j)&1)==0)
        backtrack(i,j+2,mask,nmask|(1<<j));
    if(i<n-1&&j<m-1&&((mask>>(j+1))&1)==0 && ((nmask>>(j+1))&1)==0)
        backtrack(i,j+2,mask,nmask|(1<<(j+1)));
    if(i<n-1&&j<m-1 &&((nmask>>j)&1)==0 && ((nmask>>(j+1))&1)==0)
        backtrack(i,j+1,mask,nmask|(1<<(j))|(1<<(j+1)));
    if(i<n-1&&j>0 && ((nmask>>j)&1)==0 && ((nmask>>(j-1))&1)==0)
        backtrack(i,j+1,mask,nmask|(1<<j)|(1<<(j-1)));
}

void lastbt(int j,int base,int mask) {
	if(j>m) return ;
	if(mask==(1<<m)-1) {
		dp[n][mask] += dp[n-1][base];
		return ;
	}
	if((mask>>j)&1) 
		lastbt(j+1,base,mask);
	if(j<m-1 && ((mask>>j)&1)==0 && ((mask>>(j+1)&1)==0))
		lastbt(j+2,base,mask|(1<<j)|(1<<(j+1)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    dp[0][0] = 1;
    FOR(i,0,n-1)
        FOR(mask,0,1<<m)
            backtrack(i,0,mask,0);
	FOR(mask,0,1<<m)
		lastbt(0,mask,mask);
    cout << dp[n][(1<<m)-1] << endl;
    return 0;
}
