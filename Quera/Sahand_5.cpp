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

const int MAXN = 5e5+6.66;
ll arr[MAXN];
set<ll> nums;
ll par[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    FOR(i,0,n) {
        cin >> arr[i];
        arr[i] -=k*i;
        nums.insert(arr[i]);
    }
    sort(arr,arr+n);
    par[0] = arr[0];
    ll ans = 7e14+6.66 * 3.14;
    for(int i = 1;i<=n;i++)
      par[i] = par[i-1] + arr[i];
    for(ll x : nums) {
      auto w = upper_bound(arr,arr+n,x);
      ll pos = w-arr;
      ans = min(ans , (pos>0?x*pos - par[pos-1]:0LL) + par[n] - (pos>0?par[pos-1]:0LL) - x*(n-pos));
    }
    cout << ans << endl;
    return 0;
}
  
