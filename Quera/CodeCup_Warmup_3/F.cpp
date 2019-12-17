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

const int MAXN = 1e5+100;
ll arr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    ll m;
    ll sum = 0LL;
    cin >> m >> n;
    FOR(i,0,n){
        cin >> arr[i];
        sum+= arr[i];
    }

    if(sum < m) {
        cout << 0 << endl;
        return 0;
    }

    sort(arr,arr+n);
    sum = 0;

    int sz = 1;
    RFOR(i,1,n) {
        if(m >= (arr[i]-arr[i-1])*sz) {
            m-= (arr[i]-arr[i-1])*sz;
            sz++;
        } else {
            FOR(j,0,i)
                sum += arr[j]*arr[j];
            ll x = arr[i]-m/sz;
            sum += 1LL*x*x*(sz - m%sz);
            x--;
            sum += 1LL*x*x*(m%sz);
            cout << sum << endl;
            return 0;
        }
    }

    ll x = arr[0]-m/n;
    sum += 1LL * x * x * (n - m%n);
    x--;
    sum += 1LL * x * x * (m%n);
    cout << sum << endl;
    return 0;
}
