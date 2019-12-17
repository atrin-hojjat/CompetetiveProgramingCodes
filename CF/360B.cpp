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

const int MAXN  = 2e3+100;
const ll INF = 9e9+909;
ll arr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin >> n >> k;

    FOR(i,0,n)
        cin >> arr[i];

    ll l = 0,r = 2e9;

    while(l<r) {
        ll mid = l+(r-l)/2;
        ll dp[n+1];
        dp[0] = 0;
        FOR(i,1,n) {
            dp[i] = i;
            FOR(j,0,i)
                if(abs(arr[j]-arr[i])<=mid*(i-j))
                    dp[i] = min(dp[i],dp[j] +i-j-1);
        }
        dp[n] = INF;
        FOR(i,0,n) 
            dp[n] = min(dp[n],dp[i]+n-i-1);
        if(dp[n]>k)
            l = mid+1;
        else
            r = mid;
    }

    cout << l << endl;
    return 0;
}
