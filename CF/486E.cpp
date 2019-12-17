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

const int MAXN = 1e5+66.6;
int arr[MAXN];
int lis[MAXN];
int dp[2][MAXN];
int mark[2][MAXN];
int zz = 0;

void LIS(int n,int &ans) {
    ans = 1;
    fill(lis,lis+n,0);
    lis[0] = arr[0];
    FOR(i,1,n) {
        if(arr[i] < lis[0] ) {
            lis[0] = arr[i];
            dp[zz][i] = 0;
        } else if(arr[i]>lis[ans-1]) {
            lis[ans++] = arr[i];
            dp[zz][i] = ans-1;
        } else {
            int*w = lower_bound(lis,lis+ans,arr[i]);
            *w = arr[i];
            dp[zz][i] = w-lis;
        }
    }
    zz++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
    FOR(i,0,n)
        cin >> arr[i];
    int ans1,ans2;
    LIS(n,ans1);
    FOR(i,0,ceil(n*1.0/2)) {
        arr[i] = -arr[i];
        arr[n-i-1] = -arr[n-i-1];
        swap(arr[i],arr[n-i-1]);
    }
    if(n%2)arr[n/2]*=-1;
    LIS(n,ans2);
    FOR(i,0,n)
        if(1+dp[0][i]+dp[1][n-i-1]==ans1)
            mark[0][dp[0][i]] ++;
    FOR(i,0,n) {
        if(1+dp[0][i]+dp[1][n-i-1]==ans1) {
            if( mark[0][dp[0][i]]<2)
                cout << 3;
            else 
                cout << 2;
        } else 
            cout << 1;
    }
    cout << endl;
    return 0;
}
