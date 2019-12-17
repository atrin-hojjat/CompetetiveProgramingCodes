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

const int MAXN = 3e3+100;
ll arr[MAXN];
ll dp[MAXN][MAXN];
vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n) {
        cin >> arr[i];
        arr[i] -=i;
        nums.pb(arr[i]);
    }
    sort(nums.begin(),nums.end());
    dp[0][0] = abs(arr[0] - nums[0]);
    for(int i=1;i<nums.size();i++)
        dp[0][i] = min(dp[0][i-1],abs(arr[0]-nums[i]));
    FOR(i,1,n){
        dp[i][0] = dp[i-1][0] + abs(arr[i] - nums[0]);
        FOR(j,1,nums.size())
            dp[i][j] = min(dp[i][j-1],abs(arr[i]-nums[j])+dp[i-1][j]);
    }
    cout << dp[n-1][nums.size()-1] << endl;
    return 0;
}
